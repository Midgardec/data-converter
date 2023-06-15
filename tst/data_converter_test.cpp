#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockSource.h"
#include "MockSink.h"
#include "DataConverter.h"

using testing::_;
using testing::Invoke;
using testing::Return;

TEST(DataConverterTest, ConversionTest) {
    MockSource source;
    MockSink sink;
    DataConverter converter(&source, &sink);

    EXPECT_CALL(source, hasData())
            .WillOnce(Return(true))
            .WillOnce(Return(true))
            .WillRepeatedly(Return(false));
    EXPECT_CALL(source, readByte())
            .WillOnce(Return(0b00001111))
            .WillOnce(Return(0b10010101));
    EXPECT_CALL(sink, write("15"))
            .Times(1);
    EXPECT_CALL(sink, write("v"))
            .Times(1);

    converter.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    converter.stop();
}

TEST(DataConverterTest, InvalidTypeTest) {
    MockSource source;
    MockSink sink;
    DataConverter converter(&source, &sink);

    EXPECT_CALL(source, hasData())
            .WillOnce(Return(true))
            .WillRepeatedly(Return(false));
    EXPECT_CALL(source, readByte())
            .WillOnce(Return(0b11000000));
    EXPECT_CALL(sink, write("Invalid type"))
            .Times(1);

    converter.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    converter.stop();
}


int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
