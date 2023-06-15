#include "Source.h"
#include "Sink.h"
#include "DataConverter.h"

int main() {
    // Create a source and sink object
    std::vector<uint8_t> byteData = {0b11010101};
    ISource* source = new Source(byteData);
    ISink* sink = new Sink();

    // Create a Data Converter instance
    DataConverter converter(source, sink);

    // Start the conversion process
    converter.start();

    // Wait for some time
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Stop the conversion process
    converter.stop();

    return 0;
}