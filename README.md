# 🔌 USB Device Monitoring, Behavior Analysis & Intrusion Detection System

This project is a **Linux-based system programming application written in C** that monitors USB device activity in real time. It leverages low-level system interfaces to detect USB connection and removal events, log device information, and perform basic security analysis.

---

## 📌 Overview

The system continuously listens for USB events and captures essential device details such as **vendor ID** and **product ID**. 
It maintains logs of device activity and applies simple behavioral analysis to track usage patterns. 
Additionally, it includes a **whitelist-based intrusion detection mechanism** to identify and alert users about unknown or potentially suspicious USB devices.

---

## ⚙️ Features

* 🔍 **Real-time USB Monitoring**
  Detects device connection (`add`) and removal (`remove`) events using Linux system interfaces.

* 📝 **Event Logging**
  Records device activity with timestamps, including connection and removal events.

* ⏱️ **Usage Duration Tracking**
  Measures how long a USB device remains connected to the system.

* 🔐 **Whitelist-Based Security**
  Compares connected devices against a predefined whitelist and alerts for unknown devices.

* 🚫 **Duplicate Event Filtering**
  Handles multiple low-level system events efficiently to avoid redundant logs and alerts.

---

## 🏗️ System Architecture

```
USB Device Events → Detection Module (libudev)
                     ↓
                 Logging System
                     ↓
            Behavior Analysis (Duration Tracking)
                     ↓
         Intrusion Detection (Whitelist Check)
                     ↓
                  Alert System
```

---

## 🛠️ Technologies Used

* **C Programming Language**
* Linux System Programming
* `libudev` for device event monitoring
* Standard C libraries (`stdio.h`, `string.h`, `time.h`)

---

## ▶️ How to Run

```bash
make clean // to clean previous compile
make       // to compile
sudo ./usb_monitor  // to start
```

> Note: Root privileges are required to access device-level events.

---

## 📂 Project Structure

```
usb-monitor/
├── main.c
├── monitor.c
├── logger.c
├── whitelist.c
├── analyzer.c
├── logs/
│   └── usb_log.txt
├── whitelist.conf
└── Makefile
```

---

## 🔐 Security Note

This system is **non-intrusive** and only monitors USB activity. It does not modify or access the contents of connected devices, ensuring safe operation.

---

## 🚀 Future Enhancements

* Track multiple USB devices simultaneously
* Advanced behavior analysis (usage frequency, anomaly detection)
* Graphical or web-based dashboard
* Integration with system-level USB blocking mechanisms
