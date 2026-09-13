<div align="center">

  <h1>⚡ Winsock HTTP Web Server</h1>
  <p>A lightweight, zero-dependency HTTP server built from scratch using C++ and the Windows Sockets API (Winsock2).</p>

  <p>
    <a href="#key-features">Key Features</a> •
    <a href="#tech-stack">Tech Stack</a> •
    <a href="#getting-started">Getting Started</a> •
    <a href="#how-it-works">Architecture</a>
  </p>

  <!-- Animated Header Badges & Widgets -->
  <p>
    <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=18&pause=1000&color=00F0FF&center=true&vCenter=true&width=500&lines=Built+with+Low-Level+Winsock2;Handles+HTTP%2F1.1+Requests;Zero+External+Dependencies;Pure+C%2B%2B20+Networking" alt="Typing SVG" />
  </p>

  <p>
    <img src="https://img.shields.io/badge/Language-C%2B%2B17%2F20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
    <img src="https://img.shields.io/badge/API-Winsock2-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Winsock" />
    <img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge&logo=windows11&logoColor=white" alt="Windows" />
    <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License" />
  </p>

</div>

---

<Image src="image_agent_tag_8224438700932331097" alt="Network architecture server diagram showing client-server flow" caption="Client-Server Network Flow" />

---

## 🚀 Key Features

* **Zero External Dependencies**: Built entirely with raw Win32/Winsock2 APIs (`ws2_32.lib`) and standard C++ libraries.
* **HTTP/1.1 Compliant**: Parses incoming GET requests and crafts valid raw HTTP response headers (`200 OK`, `404 Not Found`).
* **Low-Level Socket Management**: Demonstrates explicit lifecycle management including `WSAStartup`, socket binding, listening queues, and graceful connection teardowns.
* **Real-Time Terminal Logging**: Prints incoming request headers, client IP addresses, and assigned connection ports live.

---

## 🛠️ Tech Stack

<div align="center">

| Component | Technology | Description |
| :--- | :--- | :--- |
| **Language** | `C` / `C++17` | Core application logic and memory management |
| **Networking API** | `Winsock2` (`WinSock2.h`) | Windows socket networking interface |
| **Library** | `ws2_32.lib` | Windows Sockets system library |
| **Compiler Support** | `MSVC` / `MinGW (GCC)` | Native compilation on Windows |

</div>

---

## ⚙️ Getting Started

### Prerequisites
* Windows OS
* C++ Compiler: **MSVC** (Visual Studio / Developer Command Prompt) OR **MinGW-w64 (GCC)**

### Compilation & Running

Compile the Source Code

Using MinGW (GCC / Clang):

1 **Compile**
```bash
g++ main.cpp -o main.exe -lws2_32
```
MingW GCC Compiler

2 **Run**
```bash
./main.exe
```
Run exe file

3 **Use**
write folder path that you want to host, then port to start the server
then open localhost:PORT (Replace PORT with the port number you entered)

