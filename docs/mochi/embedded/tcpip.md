What are the layers of the TCP/IP model? #tcpip #networking #embedded

---

The **TCP/IP model** (DoD / Internet suite) has **four layers**. Top to bottom:

| Layer | Also called | Role |
|-------|-------------|------|
| **4 — Application** | — | End-user protocols and APIs (HTTP, DNS, SMTP, TLS). |
| **3 — Transport** | Host-to-host | **TCP** (reliable, connection-oriented) or **UDP** (connectionless). Ports, segmentation, flow control. |
| **2 — Internet** | Network | **IP** — logical addressing, routing between networks. ICMP, ARP helpers live here. |
| **1 — Network access** | Link / interface | Framing on a physical link (Ethernet, Wi‑Fi). MAC addresses, switches. |

Data **encapsulates** down the stack (add headers) and **decapsulates** up at the receiver. TCP/IP is the practical stack the Internet runs on; it is often compared to the **OSI 7-layer** reference model.

%%%MOCHI_CARD%%%
What are the five layers (name and purpose) used to teach networking alongside TCP/IP? #tcpip #networking #embedded

---

A common **5-layer teaching model** maps cleanly to both TCP/IP and OSI:

| # | Layer | Used for | Example protocols / data |
|---|--------|----------|---------------------------|
| **5** | **Application** | User services, app-to-app messages | HTTP, FTP, DNS, SSH |
| **4** | **Transport** | Reliable or best-effort delivery **host-to-host**; ports | TCP, UDP |
| **3** | **Network** | **Logical** addressing and **routing** across networks | IP, ICMP |
| **2** | **Data link** | **Frame** delivery on one **local** segment; MAC addresses | Ethernet, Wi‑Fi (802.11) |
| **1** | **Physical** | Bits on the medium (voltage, radio, fiber) | Cables, NIC PHY, modulation |

- **PDU names (helpful):** Application → *data*; Transport → *segment* (TCP) / *datagram* (UDP); Network → *packet*; Data link → *frame*; Physical → *bits*.

%%%MOCHI_CARD%%%
What is the TCP three-way handshake sequence? #tcpip #networking #embedded

---

Before application data flows, **TCP** opens a connection with a **three-way handshake** (client → server example):

1. **SYN** — Client sends **SYN=1**, initial **sequence number** (ISN\(_c\)), desired window/options. State: client **SYN-SENT**.
2. **SYN-ACK** — Server replies **SYN=1**, **ACK=1**, its own ISN\(_s\), ACK number = ISN\(_c\) + 1. State: server **SYN-RECEIVED**, client **ESTABLISHED** (half-open).
3. **ACK** — Client sends **ACK=1**, ACK number = ISN\(_s\) + 1. Both sides **ESTABLISHED**; reliable transfer can begin.

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
