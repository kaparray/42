# init

This is DevOps project with 3 parts.

Check tasks here [Tasks](https://github.com/kaparray/42/blob/master/init/assets/init.en.pdf)

### Part 1

Task: 01
```sh
ifconfig -l
```

Task: 02
```sh
ipconfig getifaddr en0
```

Task: 03
```sh
ifconfig en1 | grep 'ether ' | cut -d' ' -f2
```

Task: 04
```sh
route get default
```

Task: 05
```sh
nslookup  slash16.org | grep 'Server:' | awk '{print $2}'
```

Task: 06
```sh
etc/resolv.conf
```

Task: 07
```sh
nslookup slash16.org 8.8.8.8
```

Task: 08
```sh
AWS (Amazon Web Services)
# host slash16.org
# whois 52.84.197.41
```

Task: 09
```sh
163.172.250.12
163.172.250.11
163.172.250.13
```

Task: 10
```sh
traceroute slash16.org
```

Task: 11
```sh
traceroute slash16.org | grep ' 2 '
```

Task: 12
```sh
ipconfig getifaddr en0
```

Task: 13
```sh
hostname
```

Task: 14
```sh
/etc/hosts
```

Task: 15
```sh
echo "46.19.122.85    intra.42.fr" >> /etc/hosts
```
