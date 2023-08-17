# LAB 1 | Find GCD

In this lab we use 3 difference algorithm to find gcd

1. Find gcd by using prime factorization that used naive algorithm
2. Find gcd by using prime factorization but used `sive of eratosthenes`
3. Find gcd by using recursive function

## Prime Factorization

ระหว่างการใช้งานเจอปัญหาที่น่าสนใจอันหนึ่งคือถ้าทำเป็น set แล้ว intersection กันหรือเช็คแค่ว่า element ใน list นี้อยู่ในอีก list หรือไม่ List ของ Common Divisor ที่ได้จะไม่ถูกต้อง

[Intersection of two lists including duplicates?](https://stackoverflow.com/a/37645155)
วิธีการแก้ปัญหาคือใช้ Collection จะมี Class ชื่อ Counter
โดย Class นี้จะแปลง List เก็บเป็น dictionary
โดย key คือ element ใน list และ value คือจำนวนครั้งที่ element นั้นๆ ปรากฏใน list

โดยการนำ Class นี้มา intersection กัน dict ของผลลัพธ์ที่ได้จะเป็น element ที่พบทั้งสอง list และจำนวนครั้งที่พบที่น้อยที่สุดในทั้งสอง list
ตัวอย่าง

```python

from collections import Counter

list1 = [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]
list2 = [1, 2, 3, 1, 2, 3, 1, 2, 3]

c1 = Counter(list1)
c2 = Counter(list2)

print(c1)
# >>> Counter({1: 2, 2: 2, 3: 2, 4: 1, 5: 1})
print(c2)
# >>> Counter({1: 3, 2: 3, 3: 3})

print(c1 & c2)
>>> Counter({1: 2, 2: 2, 3: 2})
```

การใช้งาน Counter นี้เร็วกว่าการทำ for loop เช็คเอง เพราะ Counter ใช้ dictionary ในการเก็บข้อมูล

> **วิธีการแก้ปัญหา**
> เอา List ของ Prime Factor ที่ได้จากทั้งสองตัวมาแปลงเป็น Counter แล้ว intersection กัน แล้วเรียกใช้ method elements ของ Counter ที่ได้จากนั้นแปลงเป็น list แล้วหา product ของ list นั้น

### Naive Algorithm

### Sieve Of Eratosthenes Algorithm

## Euclidean Algorithm

[Euclidean Algorithm Visualization](https://www.geogebra.org/m/ztbesvsd)

## Performance Result

```

```
