What are the key features of the SPI protocol? #spi #embedded

---

- **Type:** Serial, synchronous, full duplex.
- **Wiring:** 4-wire protocol (SCLK, MISO, MOSI, SS).
- **Architecture:** Master/slave based.
- **Speed:** High speed; supports up to 1 Mbps.
- **Bus:** Multiple devices on one bus; only two communicate at a time.
- **Control:** Master initiates communication; only one master allowed.
- **Data:** Supports 8–16 bits; four clock modes.
- **Daisy chain:** One CS with multiple slaves in series.

```text
  +--------+      SCK      +---------+
  |        |--------------->|         |
  |        |     MOSI       |         |
  | Master |--------------->| Slave 1 |
  |        |<---------------|         |
  |        |     MISO       |         |
  |        |----- CS/SS --->|         |
  +--------+                +---------+
```

%%%MOCHI_CARD%%%
What is the function of the SCK (clock) signal in SPI? #spi #embedded

---

- **Synchronization:** Aligns master data output with slave sampling.
- **Speed:** One bit per clock cycle; frequency sets transfer rate.
- **Initiation:** Always driven by the master, which configures and generates the clock.

```text
  Master (SCK)
      |
      v
  +-------+
  | Slave |
  +-------+
```

%%%MOCHI_CARD%%%
Explain the roles of MISO and SS/CS in SPI. #spi #embedded

---

- **MISO (Master In Slave Out):** Slave → master data line (often LSB first).
- **SS/CS (Slave Select):**
  - Master selects a slave by driving its CS line **low**.
  - Idle state is **high**.
  - One CS pin per slave (parallel select); one CS with daisy-chained slaves is an alternative.

```text
  Master (CS) ----+---- (CS) Slave 1
                  |
                  +---- (CS) Slave 2
```

%%%MOCHI_CARD%%%
What are the main advantages of using the SPI protocol? #spi #embedded

---

- **Full duplex:** Simultaneous communication on MOSI and MISO.
- **High speed:** Up to about 1 Mbps (device-dependent).
- **Simplicity:** Straightforward hardware and protocol.
- **No overhead:** No start/stop bits (unlike UART framing).
- **Flexibility:** CPOL/CPHA modes suit many peripherals.
- **Low processing:** Good fit for resource-limited MCUs.

%%%MOCHI_CARD%%%
What are the limitations or disadvantages of the SPI protocol? #spi #embedded

---

- **No error checking:** No parity (UART) or ACK (I2C).
- **Short distance:** Signal degradation; not suited to long runs without differential signaling.
- **Pin usage:** Separate CS/SS per slave increases master pin count.
- **Single master:** The bus is not designed for multiple masters.
