# Research

## What is an IP address?

An IP address, or Internet Protocol address is a numeric address given to each device connected to a computer network using the Internet Protocol (IP) for communication.

An IP address has two functions:
- host or network identification
- location addressing

There are two major versions of the IP right now. The first one is IPv4 (Internet Protocol version 4) which defines its addresses in 32-bit numbers. Due to the massive growth of the internet, causing the depletion of IPv4 addresses, IPv6 was invented. The main difference with IPv4 is that IPv6 uses 128-bit numbers instead of 32-bit ones.

## What is a Netmask ? What is a subnet? What are the different ways to represent an IP address with the Netmask?

A Netmask is a mask allowing you to differentiate the part of an IP address used for routing, and the part that's being used to distinguish each computer on the network. It's simply a shorthand for describing a range of IP addresses.

- ```192.168.0.1/32``` is a netmask for only one address: ```192.168.0.1```

- ```192.168.0.1/0``` is a netmask for all the IPv4 addresses (4.3 billion!): from ```0.0.0.0``` to ```255.255.255.255```

- ```192.168.0.1/31``` is a netmask for the following IP addresses: ```192.168.0.0``` and ```192.168.0.1```

A subnet (or subnetwork) on the other hand, is an internal network. Essentially, it's a network inside the bigger network which the IP is. The access to this subnet is enabled by a Netmask.

Reading a Netmask may seem difficult, but in fact, it's very simple. The left part describes the IP address. If we take the netmask ```192.168.0.1/32``` as an example, ```192.168.0.1``` is the IP address. ```32``` indicates how digits **in binary** of the host address (```192.168.0.1```) are considered significant. The non-significant digits are considered as wild-card.

```192.168.0.1/31``` for example, indicates that the last digit (**in binary**) isn't significant, meaning this Netmask will match 2 different IP addresses:

- ```11000000.10101000.11111111.00000000``` (which equals ```192.168.0.0``` in non-binary)

- ```11000000.10101000.11111111.00000001``` (which equals ```192.168.0.1``` in non-binary)

```192.168.0.1/30``` for example, indicates that the last two digits (**in binary**) aren't significant, meaning this Netmask will match 4 different IP addresses.

## What is a broadcast address?

A broadcast address is an address which allows you to communicate with all the hosts on a given subnet. The broadcast is always the last address of a subnet and is assigned only once in each network.

If we take the ```192.168.0.1``` example again, the broadcast address will be ```192.168.0.1```.

## What are the differences between public and private IPs?

A private IP address is used in a local network and a public IP address is used in a public network. A public IP allows you to directly communicate with other devices around the world, while a private IP only allows you to communicate with devices on your local network.

The public IP is provided by the ISP (Internet Service Provider).

- You can find your public IP by looking up on Google: "what's my IP".

- You can find your private IP by using the ```ipconfig``` command in the Terminal.

## What is a class of IP addresses? 

There are 5 different classes available for an IPv4 address. Three of them (```A```, ```B``` and ```C```) are commonly used and the remaining two have more specific usecases.

|Class|Address Range|Supports|
|---|---|---|
|A|```1.0.0.1``` to ```126.255.255.254```|Supports 16 million hosts on each of 127 networks|
|B|```128.1.0.1``` to ```191.255.255.254```|Supports 65,000 hosts on each of 16,000 networks|
|C|```192.0.1.1``` to ```223.255.254.254```|Supports 254 hosts on each of 2 million networks|
|D|```224.0.0.0``` to ```239.255.255.255```|Reserved for multicast (one sender with multiple receivers) groups|
|E|```240.0.0.0``` to ```254.255.255.254```|Reserved for future use, or research and development purposes|

## What is TCP?

TCP stands for Transmission Control Protocol. It complements the Internet Protocol (IP), which is why these two protocols are often referred as *TCP/IP*.

TCP provides a reliable, error-free stream of bytes between apps running on hosts communicating via the IP network. E-mail, the World Wide Web,... all rely on *TCP/IP*. TCP allows for transmission of packets (the unit of data transmission TCP uses) of data in both directions, meaning a computer can send and receive data at the same time.

In order to allow to devices to communicate over a TCP connection, they each need to have an IPv4/IPv6 address and the desired port open which will be used to transmit the data.

## What is UDP?

UDP stands for User Datagram Protocol. It's like TCP a communication protocol, but which is specifically suited for time-sensitive transmissions such as video playback for example. The communication is faster than TCP mainly thanks to the fact that UDP does not establish a connection before data is transmitted. This speeds up the transfers, but is also more risky as it can cause some packets to be lost in transit. Aside from that, it also opens the door for DDoS attacks.

The main difference with TCP is that TCP first establishes a connection through a *handshake* and only then will data be transmitted. UDP directly sends the data, without going through that *handshake*. If a packet is lost along the way in a TCP connection, TCP will require it to be re-sent. This is not the case with UDP.

## What is the OSI model? What are the network layers?

The Open Systems Interconnection (OSI) model is a framework which seeks to standardize the communication capabilities of devices without regard to the underlying structure of these devices. The goal is pretty simple: increasing the interoperability between devices.

Following the Open Systems Interconnection (OSI) model, there are 7 network layers:

1. Physical (e.g. cable, RJ45)
2. Data Link (e.g. MAC, switches)
3. Network (e.g. IP, routers)
4. Transport (e.g. TCP, UDP, port numbers)
5. Session (e.g. Syn/Ack)
6. Presentation (e.g. encryption, ASCII, PNG, MIDI)
7. Application (e.g. SNMP, HTTP, FTP)

|Layer|Function|
|---|---|
|1. Physical Layer|Includes the physical equipment involved in the data transfer, such as the cables and switches|
|2. Data Link Layer|Facilitates the transfer of data on two devices on the **same** network|
|3. Network Layer|Facilitates the transfer of data between two different networks. If the devices are on the same network, then this layer is not necessary|
|4. Transport Layer|Responsible for end-to-end communication between two devices. It's also in charge of the control flow (determines the optimal speed of transmission) as well as error control|
|5. Session Layer|Responsible for opening and closing communication channels between two devices|
|6. Presentation Layer|Responsible for presenting the data so it can be used by the application layer. This includes translation, encryption, compressing data,...|
|7. Application Layer|Directly interacts with data from the user. Software is **not** on the application layer, it merely uses it to initiate communications|

The TCP/IP framework only uses 4 layers:

1. Network Access (or Link)
2. Internet
3. Transport (or Host-to-Host)
4. Application (or Process)
