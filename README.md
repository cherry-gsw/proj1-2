# StringUtils

A C++ library providing Python-like string manipulation utilities.

## Features

- **Slice**: Extract substrings with Python-style indexing (supports negative indices)
- **Capitalize**: Convert first character to uppercase, rest to lowercase
- **Upper/Lower**: Case conversion
- **Strip/LStrip/RStrip**: Remove whitespace from strings
- **Center/LJust/RJust**: String alignment and padding
- **Replace**: Find and replace substrings
- **Split/Join**: String tokenization and concatenation
- **ExpandTabs**: Convert tabs to spaces
- **EditDistance**: Calculate Levenshtein distance between strings

## Build

```bash
make
```

## Run Tests

```bash
make test
```

## Usage

```cpp
#include "StringUtils.h"

std::string text = "  hello world  ";
std::string result = StringUtils::Strip(text);  // "hello world"
```

## Clean

```bash
make clean
```
