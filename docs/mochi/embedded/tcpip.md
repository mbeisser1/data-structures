What is the TCP/IP model, and how does it differ from OSI? #tcpip #networking #embedded

---

**TCP/IP** is a model to **standardize computer networking** - same goal as OSI.

- **OSI**
  - Widely referenced in textbooks and interviews.
  - **Not used** as the real-world Internet stack.
- **TCP/IP**
  - The stack the **Internet actually runs on**.
- **Layer numbering**
  - Numbered **bottom-up** (Physical = 1).
  - Direction depends on whether you are **sending** (down the stack) or **receiving** (up).

%%%MOCHI_CARD%%%
What are the five layers of the TCP/IP model, and what does each represent? #tcpip #networking #embedded

---

| Layer   | Name                 | Represents                                                   | Protocols                                    | Devices                                                      |
| :-----: | :------------------: | :----------------------------------------------------------: | :------------------------------------------: | :----------------------------------------------------------: |
| **5**   | Application          | User-facing services and network applications                | HTTP/HTTPS, FTP, DNS                         | Proxy server, load balancer, application gateway             |
| **4**   | Transport            | End-to-end communication, reliability, and flow control      | TCP, UDP, SCTP                               | Firewall, load balancer (L4)                                 |
| **3**   | Network (Internet)   | Logical addressing and routing across networks               | IP (IPv4/IPv6), ICMP, ARP                    | Router, layer 3 switch                                       |
| **2**   | Data Link            | Node-to-node frame delivery; physical addressing             | Ethernet (802.3), Wi-Fi (802.11), PPP        | Switch (L2), bridge, NIC                                     |
| **1**   | Physical             | Raw bitstream transmission over a physical medium            | DSL, RS-232, OTN                             | Hub, repeater, cable (fiber/copper)                          |

%%%MOCHI_CARD%%%
How does the 5-layer TCP/IP model map to the 7-layer OSI model? #tcpip #networking #embedded

---

| TCP/IP (5)    | OSI (7)                                 |
| :-----------: | :-------------------------------------: |
| Application   | Application + Presentation + Session    |
| Transport     | Transport                               |
| Network       | Network                                 |
| Data Link     | Data Link                               |
| Physical      | Physical                                |

- **Bottom four layers**
  - Line up **directly** between TCP/IP and OSI.
- **Application layer**
  - TCP/IP **Application** = OSI layers **5, 6, and 7** combined.

%%%MOCHI_CARD%%%
How does encapsulation work in TCP/IP, and what is each layer's PDU called? #tcpip #networking #embedded

---

- **Encapsulation (sender, top to bottom)**
  - L5: application **data**.
  - L4: add **TCP** header (src/dst **ports**, **sequence numbers**) → **segment**.
  - L3: add **IP** header (src/dst **IP addresses**) → **packet**.
  - L2: add **Ethernet** header (src/dst **MAC**) + **trailer** (error check) → **frame**.
  - L1: transmit **bits** on the wire.
- **PDU names**

| Layer   | PDU name   |
| :-----: | :--------: |
| **5**   | Data       |
| **4**   | Segment    |
| **3**   | Packet     |
| **2**   | Frame      |

```text
  Encapsulation stack (sender, top to bottom)

  L5  +------------------+
      |      DATA        |
      +------------------+
  L4  +------+------------------+
      | TCP  |      DATA        |  = SEGMENT
      +------+------------------+
  L3  +-----+------+------------------+
      | IP  | TCP  |      DATA        |  = PACKET
      +-----+------+------------------+
  L2  +-----+-----+------+------+-----+
      | ETH | IP  | TCP  | DATA | ETH |  = FRAME
      +-----+-----+------+------+-----+
      ^hdr                          ^trailer
```

- **Decapsulation (receiver)**
  - Check destination **MAC** on the frame → **IP** on the packet → **TCP/UDP** on the segment → deliver **data** to the application.

%%%MOCHI_CARD%%%
What is the TCP three-way handshake sequence? #tcpip #networking #embedded

---

Before application data flows, **TCP** opens a connection with a **three-way handshake** (client → server example):

1. **SYN** - Client sends **SYN=1**, initial **sequence number** (ISN\(_c\)), desired window/options. State: client **SYN-SENT**.
2. **SYN-ACK** - Server replies **SYN=1**, **ACK=1**, its own ISN\(_s\), ACK number = ISN\(_c\) + 1. State: server **SYN-RECEIVED**, client **ESTABLISHED** (half-open).
3. **ACK** - Client sends **ACK=1**, ACK number = ISN\(_s\) + 1. Both sides **ESTABLISHED**; reliable transfer can begin.

```text
  Client                          Server
    |                               |
    | -------- SYN (seq=x) -------->|
    |<----- SYN-ACK (seq=y, ack=x+1)|
    | -------- ACK (ack=y+1) ------>|
    |        connection open         |
```

- **Why three steps?** Both sides must agree on **initial sequence numbers** and confirm the peer is reachable (avoids stale duplicate SYNs wasting server state).
- **Teardown** is separate: **FIN / ACK** four-way close (often described as three FIN/ACK exchanges plus a final ACK).
