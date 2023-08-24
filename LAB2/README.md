# LAB 2 | Find Path and Hamiltonian (Brute force)

ในแลปนี้ใช้ Brute force algorithm เพื่อ traverse ไปใน Undireted Graph ที่ Represent ด้วย Adjacency Matrix

1. หาเส้นทาง (Path) จากจุด u (Source) ไปยังจุด v (Destination)
2. หา Hamiltonian Path หรือ Cycle

## Knowledge

### Path

Path คือ ลำดับของ vertex ที่เชื่อมกัน โดยที่ vertex ติดกันจะเชื่อมกันด้วย edge (เส้น) และ vertex ตัวแรกจะเรียกว่า source และ vertex ตัวสุดท้ายจะเรียกว่า destination
โดยการ Traverse จะเริ่มจาก source ไปยัง destination โดยการเดินทางจะเป็นการเดินทางเส้นตรงเท่านั้นไม่ซ้ำ vertex ที่เดินทางแล้ว

### Hamiltonian Path/Cycle

Hamiltonian Path คือ Path ที่เดินทางผ่านทุก vertex ที่มีใน graph และเดินทางเส้นตรงเท่านั้นไม่ซ้ำ vertex ที่เดินทางแล้ว แต่ไม่จำเป็นต้องเดินทางผ่านทุก edge ใน graph และเริ่มต้นจาก vertex ใดก็ได้

Hamiltonian Cycle คือ Hamiltonian Path ที่เริ่มต้นและสิ้นสุดที่ vertex เดียวกัน

## Path Finding Algorithm

## Hamiltonian Path/Cycle Finding Algorithm
