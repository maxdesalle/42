#!/bin/sh

telegraf &
vsftpd /etc/vsftpd/vsftpd.conf
