#ifndef SHOWUNDERSCORES_H
#define SHOWUNDERSCORES_H

#include "all_tests.h"

TEST(showunderscores, starts_with_space)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, " Writesomething" + std::to_string(i));
        output_text += "_Writesomething" + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showunderscores, space_in_the_middle)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "Write something" + std::to_string(i));
        output_text += "Write_something" + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showunderscores, space_in_the_end)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "Writesomething " + std::to_string(i));
        output_text += "Writesomething_" + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showunderscores, multispace)
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, " Write something " + std::to_string(i));
        output_text += "_Write_something_" + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showunderscores, numbers) //added
{
    std::string output_text = "";
    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, " 1 2 3 4 5 " + std::to_string(i));
        output_text += "_1_2_3_4_5_" + std::to_string(i) + "\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showunderscores, nothing)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif // SHOWUNDERSCORES_H
