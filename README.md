# 🚀 Parallel Computing Playground

[![Stars](https://img.shields.io/github/stars/Sinchana-K28/Parallel-Computing?style=flat&logo=github)](https://github.com/Sinchana-K28/Parallel-Computing/stargazers)
[![Forks](https://img.shields.io/github/forks/Sinchana-K28/Parallel-Computing?style=flat&logo=github)](https://github.com/Sinchana-K28/Parallel-Computing/network/members)
[![Issues](https://img.shields.io/github/issues/Sinchana-K28/Parallel-Computing?style=flat&logo=github)](https://github.com/Sinchana-K28/Parallel-Computing/issues)

---

⚡ *Hands-on exploration of **parallel programming in C** — from threads to OpenMP and MPI.*  
🎓 Perfect for **students, devs, and curious minds** diving into high-performance computing.

---

## ✨ What's Inside?
- 🧑‍💻 **9+ C Programs** (`p1.c` → `p9.c`)  
- 📄 **Learning Notes** → `parallel computing.pdf`  
- ⚙️ Examples of **Threads | OpenMP | MPI**  

---

## 🚀 Quick Start

```bash
# Clone
git clone https://github.com/Sinchana-K28/Parallel-Computing.git
cd Parallel-Computing

# Compile & Run
gcc -o p1 p1.c -fopenmp   # example
./p1

▶️ Usage
Compile and run
# Basic compile
gcc -o p1 p1.c
./p1

# With pthreads
gcc -o p2 p2.c -pthread
./p2

# With OpenMP
gcc -o p3 p3.c -fopenmp
./p3

# With MPI
mpicc -o p4 p4.c
mpirun -np 4 ./p4
