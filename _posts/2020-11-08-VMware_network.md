---
layout: post
title:  "VMware_network Error"
category: "개발"
date:   2020-11-09
excerpt: "Vmware 네트워크 에러 현상"
project: false
comments: true
---

오류 배경
==========
hackerschool ftz를 vmware에서 가상환경 구축하여 xshell로 접속하려 했음

그러나
-------
IP확인 후 xshell접속을 시도했는데 IP확인을 할수없어 실패

확실하진 않지만 아마 IP할당이 되지 않아 IP를 확인할수 없는 상황

* ifconfig를 입력하였을 때

![ifconfig](/assets/img/ifconfig.JPG)

* sudo service network restart 입력시

![restart](/assets/img/restart%20net.JPG)

1. 설정 파일 변경
sudo vi /etc/sysconfig/network-scripts에 ifcfg-eth0 로 파일 수정
맨 밑에 check_link_down() { retrun 1; } 추가

![ifcfg](http://pds27.egloos.com/pds/201305/15/48/f0062448_519360ea84d76.png)


/etc/sysconfig/networking/devices/ifcfg-eth0             <- 이 파일이 없을 경우, 생성해준다.

/etc/sysconfig/networking/profiles/default/ifcfg-eth0   <- 이 파일이 없을 경우, 안만들어도 된다.

이렇게 하고 다음

#ifup eth0를 입력하거나 리눅스 재시작시 인터넷 되면 좋겠다.

2. vmware 가상머신 설정확인

![networkedirot](http://pds21.egloos.com/pds/201305/15/48/f0062448_5193636dda2c8.png)

NAT로 설정을 해놔야 한다. 

각각의 설정에서도 한번씩 확인해주자
![eachsettings](http://pds25.egloos.com/pds/201305/15/48/f0062448_5193644e2d30f.png)

* 일단 여기까지 했는데 안됨
그러면 IP를 할당해봅시다.

리눅스에서 IP할당하는 방법
---------------------------

1. /etc/sysconfig/network 파일을 편집합니다. (화살표 오른쪽은 넣지 마십시오 --;;) 
  NETWORKING=yes -> network 지원 
  HOSTNAME=aaaa -> 호스트 이름 (암거나) 

2. 실제적으로 구동할 랜카드의 설정 파일을 편집합니다. 
  /etc/sysconfig/network-scripts 디렉토리로 이동하여, ifcfg-eth0 파일을 편집합니다. 
  없을 경우 만들어야 합니다. (ifcfg-< 장치이름>) 

* DHCP의 경우 : 
  DEVICE=eth0 → 장치에 따라 변경됨 
  ONBOOT=yes → 부팅시 활성화 
  BOOTPROTO=dhcp → IP동적 할당으로 설정 
  IPADDR= 
  NETMASK= 
  GATEWAY=192.168.0.1 → 고객님의 공유기의 IP를 적어줍니다. 


* 고정 IP의 경우 
  DEVICE=eth0 
  ONBOOT=yes 
  BOOTPROTO=static 
  IPADDR=192.168.0.2 
  → 지정하고 싶은 IP를 적어줍니다. 
  단, 공유기가 제공할 수 있는 IP대를 적어주어야 합니다. 
  일반적으로는 192.168.0.xxx로 적으시면 됩니다. 

NETMASK=255.255.255.0 →공유기가 위치한 서브넷을 적어줍니다. 보통예와 같습니다. 
GATEWAY=192.168.0.1 →저희 공유기의 IP를 적어줍니다. 

기본적인 설정파일의 편집이 끝나면, 다음의 명령을 사용하여 랜카드 IP할당을 시도합니다. 

root#ifup eth0 →ifup < 장치이름> 

반대로 IP 할당을 해제하고 싶으면 ifdown 명령을 사용합니다. 
위의 명령이 먹히지 않으면 ifconfig eth0 up과 ifconfig eth0 down 명령을 
사용합니다. 


** netconfig tool을 사용하는 방법 ** 
(이 방법은 단 한 개의 장치 (eth0)만이 설정 가능합니다.) 

netconfig를 실행합니다. 
root#netconfg 
ENTER를 계속 눌러 Configure TCP/IP 화면으로 이동합니다. 

* DHCP를 사용하는 경우 

Use dynamic IP configuration을 클릭합니다. 
Default gateway부분만 공유기의 IP (192.168.0.1)로 설정하고 ENTER를 눌러 netconfig를 종료합니다. 

* 고정 IP를 사용하는 경우 
IP address : 192.168.0.2 → 공유기에서 제공되는 범위의 IP 
Netmask : 255.255.255.0 → 공유기가 사용하는 서브넷 
Default gateway (IP): 192.168.0.1 → 공유기의 IP 

아 다안돼

다시 확인해보니 NAT를 사용해야하는데 그러려면 vmnet8이 열려있어야 했다.
하지만 나는 vmnet1와 host만 열려있었고, 그래서 NAT을 사용하지 못했다. 그래서 
1. virtual Network Editor에 가서 하단 Change Settings를 누르고
2. VMnet8에서 connet a host virtual adapter to this network에 체크
3. Use Local DHCP어쩌구도 체크
4. Apply후에 FTZ training init 6(재부팅) 하면 정상작동!


<h1>해결</>

며칠후 또 안돼

보니까 서비스에서 VMware DHCP랑 네트워크가 실행 중지중

실행하면 바로 네트워크 실행 가능

<h1>해결

