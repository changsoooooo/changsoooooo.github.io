---
layout: post
title:  "OpenSSL SSL Error"
category: "개발"
date:   2020-11-09
excerpt: "크롤링 할때 OpenSSL SSL Error가 나오는 현상"
project: false
comments: true
---

OpenSSL.SSL.Error
=================

크롤링을 하려고 requests패키지를 사용했다. 그리고 긁는데 

```
import requests
from bs4 import BeautifulSoup

#특정 url에 접속하는 요청 객체 생성
request = requests.get("https://software.cbnu.ac.kr")
```

이렇게 코드를 짰는데

```
Traceback (most recent call last):
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\contrib\pyopenssl.py", line 453, in wrap_socket
    cnx.do_handshake()
  File "C:\Users\user\Anaconda3\lib\site-packages\OpenSSL\SSL.py", line 1915, in do_handshake
    self._raise_ssl_error(self._ssl, result)
  File "C:\Users\user\Anaconda3\lib\site-packages\OpenSSL\SSL.py", line 1647, in _raise_ssl_error
    _raise_current_error()
  File "C:\Users\user\Anaconda3\lib\site-packages\OpenSSL\_util.py", line 54, in exception_from_error_queue
    raise exception_type(errors)
OpenSSL.SSL.Error: [('SSL routines', 'tls_process_server_certificate', 'certificate verify failed')]

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\connectionpool.py", line 600, in urlopen
    chunked=chunked)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\connectionpool.py", line 343, in _make_request
    self._validate_conn(conn)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\connectionpool.py", line 839, in _validate_conn
    conn.connect()
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\connection.py", line 344, in connect
    ssl_context=context)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\util\ssl_.py", line 344, in ssl_wrap_socket
    return context.wrap_socket(sock, server_hostname=server_hostname)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\contrib\pyopenssl.py", line 459, in wrap_socket
    raise ssl.SSLError('bad handshake: %r' % e)
ssl.SSLError: ("bad handshake: Error([('SSL routines', 'tls_process_server_certificate', 'certificate verify failed')])",)

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\adapters.py", line 449, in send
    timeout=timeout
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\connectionpool.py", line 638, in urlopen
    _stacktrace=sys.exc_info()[2])
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\urllib3\util\retry.py", line 398, in increment
    raise MaxRetryError(_pool, url, error or ResponseError(cause))
urllib3.exceptions.MaxRetryError: HTTPSConnectionPool(host='software.cbnu.ac.kr', port=443): Max retries exceeded with url: / (Caused by SSLError(SSLError("bad handshake: Error([('SSL routines', 'tls_process_server_certificate', 'certificate verify failed')])")))

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "crawling.py", line 5, in <module>
    request = requests.get("https://software.cbnu.ac.kr")
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\api.py", line 75, in get
    return request('get', url, params=params, **kwargs)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\api.py", line 60, in request
    return session.request(method=method, url=url, **kwargs)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\sessions.py", line 533, in request
    resp = self.send(prep, **send_kwargs)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\sessions.py", line 646, in send
    r = adapter.send(request, **kwargs)
  File "C:\Users\user\AppData\Roaming\Python\Python37\site-packages\requests\adapters.py", line 514, in send
    raise SSLError(e, request=request)
requests.exceptions.SSLError: HTTPSConnectionPool(host='software.cbnu.ac.kr', port=443): Max retries exceeded with url: / (Caused by SSLError(SSLError("bad handshake: Error([('SSL routines', 'tls_process_server_certificate',
'certificate verify failed')])")))
```
무수한 오류가 발생했다. 그래서 저기서 키워드인거 같은 
```
requests.exceptions.SSLError: HTTPSConnectionPool(host='software.cbnu.ac.kr', port=443): Max retries exceeded with url: / (Caused by SSLError(SSLError("bad handshake: Error([('SSL routines', 'tls_process_server_certificate',
'certificate verify failed')])")))
```
을 찾아서 검색해봤는데 https가 적용된 페이지의 내용을 가져올때 발생하는 보안 오류였다.

그래서 해결방법은/

```
import requests
from bs4 import BeautifulSoup

#특정 url에 접속하는 요청 객체 생성
request = requests.get("https://software.cbnu.ac.kr", verify=False)
```
verify=False를 붙혀주면 된다. 기본값은 True이다.
