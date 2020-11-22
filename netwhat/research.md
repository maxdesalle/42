# Research

## What is an IP address?
An IP address, or Internet Protocol address is a numeric address given to each device connected to a computer network using the Internet Protocol (IP) for communication.

An IP address has two functions:
- host or network identification
- location addressing

There are two major versions of the IP right now. The first one is IPv4 (Internet Protocol version 4) which defines its addresses in 32-bit numbers. Due to the massive growth of the internet, causing the depletion of IPv4 addresses, IPv6 was invented. The main difference with IPv4 is that IPv6 uses 128-bit numbers instead of 32-bit ones.

---

## What is a Netmask
A Netmask is a mask allowing you to differentiate the part of an IP address used for routing, and the part that's being used to distinguish each computer on the network. It's simply a shorthand for describing a range of IP addresses.

- ```192.168.0.1/32``` is a netmask for only one address: ```192.168.0.1```

- ```192.168.0.1/0``` is a netmask for all the IPv4 addresses (4.3 billion!): from ```0.0.0.0``` to ```255.255.255.255```

- ```192.168.0.1/31``` is a netmask for the following IP addresses: ```192.168.0.0``` and ```192.168.0.1```

Reading a Netmask may seem difficult, but in fact, it's very simple. The left part describes the IP address. If we take the netmask ```192.168.0.1/32``` as an example, ```192.168.0.1``` is the IP address. 
