#include "gtest/gtest.h"

extern "C" {
#include "stdint.h"
#include "Vec.h"
}

TEST(Vec, value) {
    Vec v = Vec_value(10, sizeof(int16_t));
    ASSERT_EQ(0, v.length);
    ASSERT_EQ(10, v.capacity);
    ASSERT_STREQ((char*)v.buffer, "");
    Vec_drop(&v);
}

TEST(Vec, drop) {
    Vec v = Vec_value(10, sizeof(int16_t));
    Vec_drop(&v);
    ASSERT_EQ(0, v.length);
    ASSERT_EQ(0, v.capacity);
    ASSERT_EQ(nullptr, v.buffer);
}

TEST(Vec, ref) {
    Vec v = Vec_value(10, sizeof(int16_t));
    ASSERT_EQ(v.buffer, Vec_ref(&v, 0));
    Vec_drop(&v);
}

TEST(Vec, ref_1) {
    Vec v = Vec_value(10, sizeof(int16_t));
    int16_t *buffer = (int16_t*) v.buffer;
    buffer[0] = 255;
    buffer[1] = 512;
    v.length = 2;
    ASSERT_EQ(&buffer[0], Vec_ref(&v, 0));
    ASSERT_EQ(&buffer[1], Vec_ref(&v, 1));
    Vec_drop(&v);
}

TEST(Vec, set) {
    Vec v = Vec_value(1, sizeof(int16_t));

    int16_t x = 1;
    Vec_set(&v, 0, &x);
    ASSERT_EQ(1, v.length);

    int16_t *buffer = (int16_t*)v.buffer;
    ASSERT_EQ(x, buffer[0]);

    Vec_drop(&v);
}

TEST(Vec, get) {
    Vec v = Vec_value(1, sizeof(int16_t));
    // Dig into the abstraction to predefine some data
    int16_t *buffer = (int16_t*)v.buffer;
    buffer[0] = 1;
    v.length = 1;

    int16_t value = 0;
    Vec_get(&v, 0, &value);
    ASSERT_EQ(1, value);

    Vec_drop(&v);
}

TEST(Vec, get_set_contract) {
    Vec v = Vec_value(1, sizeof(int16_t));
    int16_t x = 256;
    int16_t y = 512;
    ASSERT_EQ(0, Vec_length(&v));
    Vec_set(&v, 0, &x);
    ASSERT_EQ(1, Vec_length(&v));
    Vec_set(&v, 1, &y);
    ASSERT_EQ(2, Vec_length(&v));

    int16_t x_out = 0;
    int16_t y_out = 0;
    Vec_get(&v, 0, &x_out);
    Vec_get(&v, 1, &y_out);

    ASSERT_EQ(x, x_out);
    ASSERT_EQ(y, y_out);
}

// TODO: Contractual Tests


