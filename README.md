# Readers-Writers problem

## Authors
<ul>
    <li>Purinat Pattanakeaw</li>
    <li>Sarttra Prasongtichol</li>
    <li>Thachchai Pattamasrirattana</li>
</ul>

<p>
    The readers-writers problem is an example of a common computing problem
    in concurrency where many threads try to access the same shared resource at one time. Some
    threads may read and some may write, with the constraint that no process may access the
    shared resource for either reading or writing, while another process is in the act of writing to
    it. In particular, we allow two or more readers to access the shared resource simultaneously,
    while we allow only one writer to write/modify the shared resource at the same time.
</p>

# Compilation

```
gcc readwrite.c -o readwrite -lpthread
```

# Execution

```
./readwrite (writers_count) (readers_count) (output_name)
```

Example output:
```
./readwrite 1 2 output.txt
```

### Output:

R1 reads data at 1, the number is 49

W1 writes the data at 97, the number is 38

W2 writes the data at 71, the number is 82

W1 writes the data at 77, the number is 37

W1 writes the data at 94, the number is 53

R1 reads data at 9, the number is 9

W2 writes the data at 45, the number is 46

W1 writes the data at 35, the number is 34

R1 reads data at 42, the number is 93

R1 reads data at 68, the number is 28

R1 reads data at 60, the number is 22

W2 writes the data at 57, the number is 97

R1 reads data at 95, the number is 66

W1 writes the data at 13, the number is 43

R1 reads data at 6, the number is 44

W2 writes the data at 42, the number is 94

R1 reads data at 82, the number is 29

W1 writes the data at 67, the number is 9

W2 writes the data at 95, the number is 67

W1 writes the data at 71, the number is 83

W2 writes the data at 90, the number is 89

R1 reads data at 38, the number is 79

R1 reads data at 16, the number is 27

W2 writes the data at 40, the number is 68

W1 writes the data at 35, the number is 35

W2 writes the data at 72, the number is 36

W2 writes the data at 95, the number is 68

W1 writes the data at 54, the number is 69

R1 reads data at 89, the number is 98

W2 writes the data at 5, the number is 73

W1 writes the data at 23, the number is 58

R1 reads data at 13, the number is 43

W2 writes the data at 38, the number is 80

R1 reads data at 20, the number is 3

W1 writes the data at 66, the number is 78

W1 writes the data at 26, the number is 100

W2 writes the data at 63, the number is 25

W1 writes the data at 44, the number is 86

R1 reads data at 50, the number is 1

R1 reads data at 23, the number is 58

W2 writes the data at 85, the number is 96

W1 writes the data at 72, the number is 37

R1 reads data at 47, the number is 91

R1 reads data at 96, the number is 16

W1 writes the data at 23, the number is 59

W2 writes the data at 44, the number is 87

W2 writes the data at 35, the number is 36

W1 writes the data at 25, the number is 34

R1 reads data at 42, the number is 94

W1 writes the data at 79, the number is 70

R1 reads data at 44, the number is 87

W1 writes the data at 18, the number is 41

W1 writes the data at 92, the number is 6

W2 writes the data at 91, the number is 24

W2 writes the data at 69, the number is 34

W1 writes the data at 53, the number is 45

W1 is done.

R1 reads data at 25, the number is 34

R1 reads data at 62, the number is 49

R1 reads data at 8, the number is 23

W2 writes the data at 61, the number is 67

W2 writes the data at 35, the number is 37

R1 reads data at 95, the number is 68

W2 writes the data at 67, the number is 10

R1 reads data at 74, the number is 65

W2 is done.

R1 reads data at 56, the number is 24

R1 reads data at 72, the number is 37

R1 reads data at 94, the number is 53

R1 reads data at 55, the number is 90

R1 reads data at 7, the number is 78

R1 reads data at 93, the number is 82

R1 reads data at 80, the number is 15

R1 reads data at 55, the number is 90

R1 reads data at 63, the number is 25

R1 reads data at 76, the number is 63

R1 reads data at 49, the number is 57

R1 reads data at 44, the number is 87

R1 reads data at 8, the number is 23

R1 reads data at 51, the number is 53

R1 reads data at 3, the number is 58

R1 reads data at 31, the number is 26

R1 reads data at 19, the number is 12

R1 reads data at 9, the number is 9

R1 reads data at 29, the number is 35

R1 reads data at 54, the number is 69

R1 reads data at 37, the number is 49

R1 reads data at 17, the number is 29

R1 reads data at 0, the number is 7

R1 reads data at 64, the number is 1

R1 reads data at 48, the number is 94

R1 reads data at 50, the number is 1

R1 is done.