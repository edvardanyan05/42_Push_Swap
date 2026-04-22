*This project has been created as part of the 42 curriculum by edmvarda, mgogjyan.*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, generating the smallest possible sequence of moves.

The project requires implementing four distinct sorting strategies with different algorithmic complexities, and selecting the best strategy at runtime based on the input configuration.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack a |
| `sb` | Swap the first two elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top of stack b onto stack a |
| `pb` | Push top of stack a onto stack b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

### Sorting Strategies

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sorting | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Disorder-based selection (default) | varies |

The adaptive strategy measures the disorder of the input before sorting and selects the most appropriate algorithm:
- `disorder < 0.2` → Simple sort O(n²)
- `0.2 ≤ disorder < 0.5` → Chunk sort O(n√n)
- `disorder ≥ 0.5` → Radix sort O(n log n)

---

## Instructions

### Compilation

```bash
make
```

Other Makefile rules:
```bash
make clean
make fclean
make re
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers>
```

Examples:
```bash
./push_swap 3 2 1 5 4
./push_swap --simple 5 4 3 2 1
./push_swap --complex 42 7 -3 100 0
./push_swap --bench 3 2 1 5 4
./push_swap --simple --bench 5 4 3 2 1
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Error Handling

The program prints `Error` to stderr and exits on:
- Non-integer arguments
- Integers outside INT_MIN to INT_MAX range
- Duplicate values
- Invalid flags

---

## Resources

- 42 intranet push_swap subject
- Stack data structure references
- Sorting algorithm resources
- GNU C Library documentation
- peer discussions and code reviews
- AI tools used only for reviewing code for potential issues

### Algorithm Justification

**Simple sort O(n²):** Selection sort adaptation. Repeatedly finds the minimum in stack A and pushes to B, sorts remaining 3 elements, pushes back. Best for low disorder inputs.

**Chunk sort O(n√n):** Divides value range into √n chunks. Pushes elements chunk by chunk to B, then pushes back by finding maximum each time. Best for medium disorder.

**Radix sort O(n log n):** LSD radix sort on normalized indexes (0 to n-1). Each pass checks one bit — bit=0 stays in A, bit=1 goes to B. After log₂(n) passes the stack is sorted. Best for high disorder.

**Adaptive:** Computes disorder before sorting and selects the algorithm matching the input's disorder regime.

### AI Usage

AI (Claude) was used to:
- Debug parsing and validation logic
- Explain sorting algorithm concepts
- Review operation implementations
- Guide algorithm structure

All code was written, reviewed, and understood by both team members.

---