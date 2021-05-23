#ifndef RN_H
#define RN_H

#include "all_tests.h"

TEST(rn, cursor_on_fisrt)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "|Write something" + std::to_string(i) + "\n";
        } else if (i == 1){
            append_line(txt, "");
        } else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rn, cursor_on_centre)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "|Write something" + std::to_string(i) + "\n";
        } else if (i == 6){
            append_line(txt, "");
        } else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rn, cursor_on_last)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0; i < 10; i++) {
        if (i==9) {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "|Write something" + std::to_string(i) + "\n";
        }
        else {
            append_line(txt, "Write something" + std::to_string(i));
            output_text += "Write something" + std::to_string(i) + "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rn, one_line)
{
    std::string output_text = "\n";

    text txt = create_text();
    append_line(txt, "");

    rn(txt);

    ASSERT_DEATH(show(txt), "");
}

TEST(rn, no_lines)
{
    std::string output_text = "There are already no any lines in the text!\n";

    text txt = create_text();

    testing::internal::CaptureStderr();

    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStderr();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


#endif // RN_H
