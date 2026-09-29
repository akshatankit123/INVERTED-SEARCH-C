# Inverted Search in C

A C-based inverted search project that creates an index of words from multiple text files and efficiently identifies the files containing a given word. The project uses hashing and linked lists to organize and retrieve word-to-file mappings.

## Features

* Create an inverted index from multiple text files
* Search for a word across indexed files
* Display the files and occurrence count for a searched word
* Update the index with additional files
* Save and retrieve indexed information
* Handle multiple words and files efficiently

## Technologies Used

* C
* File Handling
* Structures
* Pointers
* Dynamic Memory Allocation
* Hashing
* Linked Lists

## How It Works

The project reads words from multiple text files and stores them in a hash table. Each unique word is associated with a list of files in which the word appears, along with the number of occurrences.

For example:

```text
Word: embedded

File 1 → 3 occurrences
File 2 → 5 occurrences
File 4 → 1 occurrence
```

This allows the program to search for a word and quickly identify the files containing it.

## Operations

### 1. Create Database

Reads the input text files and creates the inverted index.

### 2. Display Database

Displays the complete indexed information including words, files, and occurrence counts.

### 3. Search

Searches for a specific word and displays the files where it occurs.

### 4. Update Database

Adds information from additional text files to the existing index.

### 5. Save Database

Stores the indexed information into a file for future use.

## Project Structure

```text
inverted-search-c/
├── main.c
├── create_database.c
├── display_database.c
├── search.c
├── update_database.c
├── save_database.c
├── headers.h
├── README.md
└── ...
```

## Example

Suppose the input files contain:

```text
file1.txt → embedded C programming
file2.txt → embedded systems programming
file3.txt → C programming
```

Searching for:

```text
embedded
```

may produce:

```text
Word: embedded
file1.txt → 1 occurrence
file2.txt → 1 occurrence
```

## Learning Outcomes

This project provides practical experience with:

* Hash tables
* Linked lists
* File handling
* String processing
* Dynamic memory allocation
* Modular C programming
* Searching and indexing techniques

## Author

Akshat Raj
