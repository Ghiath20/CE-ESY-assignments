# Circular Buffer Implementation in C

A simple circular buffer (ring buffer) implementation in C for storing characters.

## Description

This program implements a circular buffer data structure with a fixed capacity of 20 characters. It demonstrates basic queue operations including:
- Inserting elements (write)
- Removing elements (read)
- Checking if the buffer is empty or full

The program then demonstrates the buffer by:
1. Taking a user's name as input
2. Appending "CE-ESY" to it
3. Writing each character to the circular buffer
4. Reading and printing all characters in FIFO order

## Data Structure

The `RingBuffer` structure contains:
- `buffer[MAX_SIZE]` - Array to store characters
- `head` - Index of the front element (read position)
- `tail` - Index of the next write position
- `itemCount` - Number of elements currently in buffer

## Functions

| Function | Description |
|----------|-------------|
| `initialize(RingBuffer *rb)` | Initializes the buffer to empty state |
| `isBufferEmpty(const RingBuffer *rb)` | Returns 1 if buffer is empty, 0 otherwise |
| `isBufferFull(const RingBuffer *rb)` | Returns 1 if buffer is full, 0 otherwise |
| `insert(RingBuffer *rb, char element)` | Adds an element to the buffer (prints "Overflow" if full) |
| `removeElement(RingBuffer *rb)` | Removes and returns the front element (prints "Underflow" if empty) |

## Compilation

```bash
gcc -o ringbuffer main.c
