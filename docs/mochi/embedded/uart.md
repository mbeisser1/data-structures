What are the key features of the UART protocol? #uart #embedded

---

**UART** (Universal Asynchronous Receiver/Transmitter) is a serial protocol for point-to-point data transfer between two devices.

- **Wiring**
  - 2-wire protocol: **Tx** (transmit) and **Rx** (receive).
- **Type**
  - Asynchronous, serial, **full duplex**.
- **Data**
  - Typically **8-bit** / ASCII; supports **5-8 bit** data width modes.
- **Frame**
  - **Start bit** → data bits → **stop bit(s)**.
- **Parity**
  - Optional parity generation and checking: **odd**, **even**, or **none**.
- **Stop bits**
  - **One or two** stop bits.

![UART - Tx and Rx, asynchronous serial|450](https://raw.githubusercontent.com/mbeisser1/data-structures/master/docs/mochi/embedded/img/uart-bus.png)

%%%MOCHI_CARD%%%
How does a UART frame work from start bit to stop bit? #uart #embedded

---

- **Start bit**
  - Line idles **high**; transmitter pulls **low** for one bit period.
  - Receiver detects the **high → low** edge, then samples at the agreed **baud rate**.
- **Data frame**
  - The payload: typically **5-9 bits** (often **8** without parity).
  - Data sent **LSB first** (D0 → D7).
  - Receiver samples near the **center** of each bit period.
- **Parity bit** (optional)
  - Extra bit for odd/even error checking between data and stop.
- **Stop bit**
  - Marks end of packet; line held **high** (logic 1).
  - **One or two** bit periods (one is most common).

![UART frame - start, data D0-D7, parity, stop|450](https://raw.githubusercontent.com/mbeisser1/data-structures/master/docs/mochi/embedded/img/uart-frame.png)

%%%MOCHI_CARD%%%
How does UART parity work for error detection? #uart #embedded

---

- **What parity is**
  - Describes whether the count of **1** bits is **even** or **odd**.
- **Receiver check**
  - After the data frame, the receiver counts **1** bits and compares to the parity bit.
- **Even parity**
  - Parity bit **0** → total **1** bits in the frame (data + parity) should be **even**.
- **Odd parity**
  - Parity bit **1** → total **1** bits should be **odd**.
- **No error**
  - Parity bit matches the data → transmission assumed **OK**.
- **Error detected**
  - Parity **0** but total is **odd**, or parity **1** but total is **even** → a bit was corrupted.

%%%MOCHI_CARD%%%
What is baud rate, and why must UART devices agree on it? #uart #embedded

---

- **Definition**
  - Number of **signal changes (symbols) per second** on the line.
  - Often expressed in **bps** (bits per second).
- **UART requirement**
  - Transmitter and receiver must use the **same baud rate** or data is misread.
- **Common rates**
  - 4800, 9600, 19200, 38400, 57600, 115200.
- **Baud rate vs bit rate**
  - **Bit rate** - bits (0/1) transferred per second.
  - **Baud rate** - symbols/signal changes per second.
  - **Baud rate = bit rate ÷ bits per symbol** (for UART, often 1 bit per symbol, so they match).

%%%MOCHI_CARD%%%
What are the advantages and disadvantages of UART? #uart #embedded

---

- **Advantages**
  - **No clock line** - asynchronous; no shared clock wire needed.
  - **Low cost** - simple hardware and protocol.
  - **Error detection** - optional **parity bit**.
  - **Minimal wiring** - only **2 wires** (Tx and Rx) for data.
- **Disadvantages**
  - **Small frames** - typically **8 data bits** (1 byte) per transfer.
  - **Point-to-point** - no native multi-device bus (unlike I2C/SPI).
  - **Matched baud rate** - both sides must be configured to the **same rate** manually.
