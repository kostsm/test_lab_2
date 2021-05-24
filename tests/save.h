#ifndef SAVE_H
#define SAVE_H

#include "all_tests.h"

TEST(save, nothing)
{
    text txt = create_text();
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, one_line)
{
    text txt = create_text();
    append_line(txt,"Write something");
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, several_lines)
{
    text txt = create_text();
    for (int i=0; i<10; i++)
        append_line(txt,"Write something");
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, empty_line)
{
    text txt = create_text();
    append_line(txt,"");
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

TEST(save, some_lines_are_empty)
{
    text txt = create_text();
    for (int i=0; i<10; i++)
        if (i%2==0) {
            append_line(txt,"Write something");
        } else {
            append_line(txt,"");
        }
    save(txt, test_file_1.toStdString());

    QFile file(test_file_1);
    bool res = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(res, true);

    QString line_file;
    auto line_text = txt->lines->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    removeFiles();
}

#endif // TEST_SQ_EQ_H
