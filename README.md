# C++을 사용하여 코딩 연습

```cpp
#include <bits/stdc++.h>
```

<br>

*****

<br>

```cpp
long long (%lld)          = -9,223,372,036,854,775,808 ~  9,223,372,036,854,775,807
```
```cpp
unsigned long long (%llu) =                          0 ~ 18,446,744,073,709,551,615
```
```cpp
int %d, char %c, char * (string) %s, double %lf, long long %lld
```

<br>

*****

<br>

```cpp
std::cout, std::cin --> printf(), scanf()
```
```cpp
// ex) string -> c_str()
printf("%s", str.c_str())
```

<br>

*****

<br>

### 사용하는 헤더 및 함수

* **algorithm**

  - unique
  - find
  - *max_element
  - sort
  - next_permutation
    
<br>

* **queue**

  - queue
  - priority queue
    
<br>

* **sstream**

  - stringstream

<br>

* **functional**

  - greater<int>
  - less<int>

<br>

* **cctype**

  - isdigit()
  - isalpha()

<br>

* **iomanip**

  - fixed
  - setprecision()

*****

<br>

* **solution**

  - 유클리드 호제법
  - 에라토스테네스의 체 (소수판별 수가 많을 때)

<br>

*****

<br>

* **Read File**
  ```cpp
  freopen("sample_input.txt", "r", stdin);
  ```