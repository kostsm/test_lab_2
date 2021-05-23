#ifndef MPWEB_H
#define MPWEB_H

#include "all_tests.h"

TEST(mpweb, on_first_begin)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i==0) {
        append_line(txt, "Write something" + std::to_string(i));
        output_text += "|Write something" + std::to_string(i) + "\n";
        }
        else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    mpweb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb, on_first)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i==0) {
        append_line(txt, "Write something" + std::to_string(i));
        output_text += "Write| something" + std::to_string(i) + "\n";
        }
        else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 10);
    mpweb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb, on_centre_begin)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        append_line(txt, "Write something" + std::to_string(i));
        if (i == 5) {
            output_text += "|Write something" + std::to_string(i) + "\n";
        } else {
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 0);
    mpweb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


TEST(mpweb, on_centre)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i==5) {
        append_line(txt, "Write something" + std::to_string(i));
        output_text += "Write| something" + std::to_string(i) + "\n";
        }
        else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 10);
    mpweb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb, on_first_word)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i==7) {
        append_line(txt, "Write something" + std::to_string(i));
        output_text += "Writ|e something" + std::to_string(i) + "\n";
        }
        else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 7, 4);
    mpweb(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif // MPWEB_H
