# Research

## What is an IP address?
An IP address, or Internet Protocol address is a numeric address given to each device connected to a computer network using the Internet Protocol (IP) for communication.

An IP address has two functions:
- host or network identification
- location addressing

There are two major versions of the IP right now. The first one is IPv4 (Internet Protocol version 4) which defines its addresses in 32-bit numbers. Due to the massive growth of the internet, causing the depletion of IPv4 addresses, IPv6 was invented. The main difference with IPv4 is that IPv6 uses 128-bit numbers instead of 32-bit ones.

---

## What is a Netmask ? What is a subnet? What is the broadcast address of a subnet?
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

A broadcast address is an address which allows you to communicate with all the hosts on a given subnet. The broadcast is always the last address of a subnet and is assigned only once in each network.

If we take the ```192.168.0.1``` example again, the broadcast address will be ```192.168.0.1```.

---
