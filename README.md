## Data Converter

The Data Converter project is a simple application that converts data from a source to a sink based on specific rules. It takes input data, performs conversion based on the data type, and writes the converted data to the output sink.

### Features

- Converts data from a source to a sink based on specified rules.
- Supports three types of data conversion:
    - Type 0: Unsigned integer conversion.
    - Type 1: Signed integer conversion.
    - Type 2: Character conversion.
- Invalid types are handled and reported as "Invalid type" in the output.

### Getting Started

To use the Data Converter, follow these steps:

1. Clone the repository: `git clone https://github.com/Midgardec/data-converter.git`.
2. Build the project using your preferred build system.
3. Include the necessary header files and link against the Data Converter library in your project.
4. Create an instance of the `DataConverter` class, providing the appropriate source and sink objects.
5. Call the `start` method to start the conversion process.
6. Optionally, you can pause or stop the conversion process by calling the `pause` or `stop` methods, respectively.

### Example Usage

Here's an example of how to use the Data Converter:

```cpp
#include "DataConverter.h"

int main() {
    // Create a source and sink object
    ISource* source = new Source();
    ISink* sink = new Sink();

    // Create a Data Converter instance
    DataConverter converter(source, sink);

    // Start the conversion process
    converter.start();

    // Wait for some time
    // ...

    // Stop the conversion process
    converter.stop();

    // Clean up
    delete source;
    delete sink;

    return 0;
}
```

### Dependencies

The Data Converter project has the following dependencies:

- C++11 or higher


### Building and Running Tests

To run tests you can use:

- tst/data_converter_test.cpp

### Contributing

Contributions to the Data Converter project are welcome. If you find any issues or have suggestions for improvements, please create a GitHub issue or submit a pull request.

### License

The Data Converter project is licensed under the [MIT License](LICENSE).