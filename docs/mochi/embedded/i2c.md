```text
                      I2C
           Inter Integrated Circuit

    +-----------+                    +-----------+
    | Master 1  |                    | Master 2  |
    +-----+-----+                    +-----+-----+
          | \                              | |
          |  `---.                         | |
          |       \                        | |      
  Vcc=5V -+-[Rp]-*-+-----------------------*--)-----------*---------> SDA
         | [Rp]  | \                       | |            |  
         |       |  *--------------------- *-*-------*---(---------> SCL
         |       |   |    |_|_|_|          |         |    |    
         |       |   |    clock             |        |    |
    +----+-----+ |   |                      |        |    |
    | Slave 1  | |   |    +-----------+     |    +----------+
    |  0x10    | |   |    | Slave 2   |     |     | Slave 3  |
    +----------+ |   |    |  0x20     |     |     |  0x30    |
                 |   |    +-----------+     |    +----------+
    
```

What are the key features of the I2C protocol? #i2c #embedded

---

- **Topology:** Multi-master, multi-slave on one bus.
- **Type:** Serial, synchronous bus.
- **Wiring:** Half duplex; two wires — **SDA** (data) and **SCL** (clock).
- **Frequency:** Typically 100 kbps (Standard) to 400 kbps (Fast mode); higher modes exist on some devices.
- **Addressing:** **7-bit** address-based communication (10-bit extension in some systems).
- **Bus management:** Supports **arbitration** (multi-master) and **clock stretching** (slave can hold SCL low).
- **Use case:** Connects low-speed peripherals to processors and microcontrollers.
- **Range:** Short distance, intra-board communication.
- **Data:** Byte-oriented protocol; **ACK** after every transmitted byte.
- **Framing:** Data sent in defined **frames** (start, address, data, stop).
