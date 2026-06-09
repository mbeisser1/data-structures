What are the key features of the SPI protocol? #spi #embedded

---

- **Type**
  - Serial, synchronous, full duplex.
- **Wiring**
  - 4-wire protocol:
    - **SCLK** (Serial Clock) - master-driven clock; synchronizes data transfer.
    - **MOSI** (Master Out Slave In) - master → slave data.
    - **MISO** (Master In Slave Out) - slave → master data.
    - **SS/CS** (Slave Select / Chip Select) - master selects which slave is active (active **low**).
- **Architecture**
  - Master/slave based.
- **Speed**
  - High speed; supports up to 1 Mbps.
- **Bus**
  - Multiple devices on one bus; only two communicate at a time.
- **Control**
  - Master initiates communication; only one master allowed.
- **Data**
  - Supports 8-16 bits; four clock modes.
- **Daisy chain**
  - One SS/CS line with multiple slaves in series.

![SPI bus - master, slave, SCLK, MOSI, MISO, SS/CS|700](https://raw.githubusercontent.com/mbeisser1/data-structures/master/docs/mochi/embedded/spi-bus.png)

%%%MOCHI_CARD%%%
What is the function of the SCK (clock) signal in SPI, and how can the clock be configured? #spi #embedded

---

- **Synchronization**
  - Aligns master data output with slave sampling.
- **Speed**
  - One bit per clock cycle; frequency sets transfer rate.
- **Initiation**
  - Always driven by the master, which configures and generates the clock.
- **CPOL (Clock Polarity)**
  - Sets the clock’s **idle** level (high or low).
- **CPHA (Clock Phase)**
  - Sets which clock edge samples data.

**SPI clock modes (CPOL + CPHA)**

| Mode  | CPOL | CPHA | Active level | Data sampling |
|:-----:|:----:|:----:|:------------:|:--------------|
| **0** | 0    | 0    | High         | Rising edge   |
| **1** | 0    | 1    | High         | Falling edge  |
| **2** | 1    | 0    | Low          | Rising edge   |
| **3** | 1    | 1    | Low          | Falling edge  |

```text
  Master (SCK)
      |
      v
  +-------+
  | Slave |
  +-------+
```

%%%MOCHI_CARD%%%
Explain the roles of MISO and MOSI in SPI. #spi #embedded

---

- **MOSI (Master Out Slave In)**
  - The master sends data to the slave bit by bit, in serial through the MOSI line.
  - The slave receives the data at the MOSI pin. Data from master to slave is usually sent **MSB first**.
- **MISO (Master In Slave Out)**
  - The slave sends data back to the master bit by bit, in serial through the MISO line.
  - Data from slave to master is usually sent **LSB first**.

![SPI bus - master, slave, SCLK, MOSI, MISO, SS/CS|700](https://raw.githubusercontent.com/mbeisser1/data-structures/master/docs/mochi/embedded/spi-bus.png)

%%%MOCHI_CARD%%%
What is the role of SS/CS (Slave Select) in SPI? #spi #embedded

---

- **Selection**
  - The master chooses which slave to talk to by driving that slave’s **CS/SS line low**.
- **Idle state**
  - When not transmitting, CS/SS is held **high**.
- **Multiple CS/SS pins**
  - The master may have one CS/SS pin per slave - slaves wired **in parallel**.
- **Single CS/SS pin**
  - Multiple slaves can share one select line by **daisy-chaining**.

```text
  Master (CS) ----+---- (CS) Slave 1
                  |
                  +---- (CS) Slave 2
```

%%%MOCHI_CARD%%%
How does SPI work in daisy-chain mode? #spi #embedded

---

- **Shared CS/SS**
  - All slaves tie chip select together; data propagates from one slave to the next.
- **Common clock**
  - All slaves receive the same SPI clock at the same time.
- **Data path**
  - Master MOSI connects to the first slave; each slave passes data to the next in the chain.
- **Latency**
  - Clock cycles needed to reach a slave grow with its **position** in the chain.

![SPI daisy-chain - slaves in series, shared SS/CS|700](https://raw.githubusercontent.com/mbeisser1/data-structures/master/docs/mochi/embedded/spi-bus-slave-daisy-chain.png)

%%%MOCHI_CARD%%%
What are the main advantages of using the SPI protocol? #spi #embedded

---

- **Full duplex**
  - Simultaneous communication on MOSI and MISO.
- **High speed**
  - Up to about 1 Mbps (device-dependent).
- **Simplicity**
  - Straightforward hardware and protocol.
- **No overhead**
  - No start/stop bits (unlike UART framing).
- **Flexibility**
  - CPOL/CPHA modes suit many peripherals.
- **Low processing**
  - Good fit for resource-limited MCUs.

%%%MOCHI_CARD%%%
What are the limitations or disadvantages of the SPI protocol? #spi #embedded

---

- **No error checking**
  - No parity (UART) or ACK (I2C).
- **Short distance**
  - Signal degradation; not suited to long runs without differential signaling. (~3cm to 50cm depending on clock)
- **Pin usage**
  - Separate CS/SS per slave increases master pin count.
- **Single master**
  - The bus is not designed for multiple masters.
