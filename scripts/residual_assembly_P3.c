#include <stdint.h>

static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y);
static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y)
{
  for (int32_t i = 0; i <= 9; ++i)
    y[i] = x[i] + y[i];
}

void mykernel(double const *__restrict__ func0, double *__restrict__ func1, int32_t const *__restrict__ ten, int32_t const *__restrict__ ten_0, int32_t const *__restrict__ ten_1, int32_t const *__restrict__ map0, int32_t const *__restrict__ map1, int32_t const *__restrict__ map2)
{
  int32_t j_0;
  int32_t j_1;
  int32_t j_10;
  int32_t j_11;
  int32_t j_12;
  int32_t j_13;
  int32_t j_14;
  int32_t j_15;
  int32_t j_16;
  int32_t j_17;
  int32_t j_18;
  int32_t j_19;
  int32_t j_2;
  int32_t j_20;
  int32_t j_21;
  int32_t j_22;
  int32_t j_23;
  int32_t j_24;
  int32_t j_25;
  int32_t j_26;
  int32_t j_27;
  int32_t j_28;
  int32_t j_29;
  int32_t j_3;
  int32_t j_30;
  int32_t j_31;
  int32_t j_32;
  int32_t j_33;
  int32_t j_34;
  int32_t j_35;
  int32_t j_36;
  int32_t j_37;
  int32_t j_38;
  int32_t j_39;
  int32_t j_4;
  int32_t j_40;
  int32_t j_41;
  int32_t j_42;
  int32_t j_43;
  int32_t j_44;
  int32_t j_45;
  int32_t j_5;
  int32_t j_6;
  int32_t j_7;
  int32_t j_8;
  int32_t j_9;
  int32_t off_0;
  int32_t off_1;
  int32_t off_10;
  int32_t off_11;
  int32_t off_12;
  int32_t off_13;
  int32_t off_14;
  int32_t off_15;
  int32_t off_16;
  int32_t off_17;
  int32_t off_18;
  int32_t off_19;
  int32_t off_2;
  int32_t off_20;
  int32_t off_21;
  int32_t off_22;
  int32_t off_23;
  int32_t off_24;
  int32_t off_25;
  int32_t off_26;
  int32_t off_27;
  int32_t off_28;
  int32_t off_29;
  int32_t off_3;
  int32_t off_30;
  int32_t off_31;
  int32_t off_32;
  int32_t off_33;
  int32_t off_34;
  int32_t off_35;
  int32_t off_4;
  int32_t off_5;
  int32_t off_6;
  int32_t off_7;
  int32_t off_8;
  int32_t off_9;
  double t_0[10];
  double t_1[10];

  for (int32_t i_0 = 0; i_0 <= 1; ++i_0)
  {
    j_0 = i_0;
    {
      int32_t const i_3 = 0;

      j_8 = i_3;
      {
        int32_t const i_4 = 0;

        j_13 = i_4;
        j_7 = j_0;
        off_6 = j_7 + j_8;
        j_2 = j_13;
        j_1 = map0[off_6];
        off_1 = j_1;
        off_0 = ten[off_1] + j_2;
        off_9 = j_8 + j_13;
        t_0[off_9] = func0[off_0];
      }
    }
    for (int32_t i_5 = 0; i_5 <= 2; ++i_5)
    {
      j_10 = i_5;
      for (int32_t i_6 = 0; i_6 <= 1; ++i_6)
      {
        j_14 = i_6;
        j_9 = j_0;
        off_7 = j_9 * 3 + j_10;
        j_3 = map1[off_7];
        j_4 = j_14;
        off_3 = j_3;
        off_2 = ten_0[off_3] + j_4;
        off_10 = j_10 * 2 + 1 + j_14;
        t_0[off_10] = func0[off_2];
      }
    }
    for (int32_t i_7 = 0; i_7 <= 2; ++i_7)
    {
      j_12 = i_7;
      {
        int32_t const i_8 = 0;

        j_15 = i_8;
        j_11 = j_0;
        off_8 = j_11 * 3 + j_12;
        j_5 = map2[off_8];
        j_6 = j_15;
        off_5 = j_5;
        off_4 = ten_1[off_5] + j_6;
        off_11 = j_12 + 7 + j_15;
        t_0[off_11] = func0[off_4];
      }
    }
    {
      int32_t const i_9 = 0;

      j_23 = i_9;
      {
        int32_t const i_10 = 0;

        j_28 = i_10;
        j_22 = j_0;
        off_18 = j_22 + j_23;
        j_17 = j_28;
        j_16 = map0[off_18];
        off_13 = j_16;
        off_12 = ten[off_13] + j_17;
        off_21 = j_23 + j_28;
        t_1[off_21] = 0.0;
      }
    }
    for (int32_t i_11 = 0; i_11 <= 2; ++i_11)
    {
      j_25 = i_11;
      for (int32_t i_12 = 0; i_12 <= 1; ++i_12)
      {
        j_29 = i_12;
        j_24 = j_0;
        off_19 = j_24 * 3 + j_25;
        j_18 = map1[off_19];
        j_19 = j_29;
        off_15 = j_18;
        off_14 = ten_0[off_15] + j_19;
        off_22 = j_25 * 2 + 1 + j_29;
        t_1[off_22] = 0.0;
      }
    }
    for (int32_t i_13 = 0; i_13 <= 2; ++i_13)
    {
      j_27 = i_13;
      {
        int32_t const i_14 = 0;

        j_30 = i_14;
        j_26 = j_0;
        off_20 = j_26 * 3 + j_27;
        j_20 = map2[off_20];
        j_21 = j_30;
        off_17 = j_20;
        off_16 = ten_1[off_17] + j_21;
        off_23 = j_27 + 7 + j_30;
        t_1[off_23] = 0.0;
      }
    }
    dummy_kernel(&(t_0[0]), &(t_1[0]));
    {
      int32_t const i_15 = 0;

      j_38 = i_15;
      {
        int32_t const i_16 = 0;

        j_43 = i_16;
        j_37 = j_0;
        off_30 = j_37 + j_38;
        j_32 = j_43;
        j_31 = map0[off_30];
        off_25 = j_31;
        off_24 = ten[off_25] + j_32;
        off_33 = j_38 + j_43;
        func1[off_24] = func1[off_24] + t_1[off_33];
      }
    }
    for (int32_t i_17 = 0; i_17 <= 2; ++i_17)
    {
      j_40 = i_17;
      for (int32_t i_18 = 0; i_18 <= 1; ++i_18)
      {
        j_44 = i_18;
        j_39 = j_0;
        off_31 = j_39 * 3 + j_40;
        j_33 = map1[off_31];
        j_34 = j_44;
        off_27 = j_33;
        off_26 = ten_0[off_27] + j_34;
        off_34 = j_40 * 2 + 1 + j_44;
        func1[off_26] = func1[off_26] + t_1[off_34];
      }
    }
    for (int32_t i_19 = 0; i_19 <= 2; ++i_19)
    {
      j_42 = i_19;
      {
        int32_t const i_20 = 0;

        j_45 = i_20;
        j_41 = j_0;
        off_32 = j_41 * 3 + j_42;
        j_35 = map2[off_32];
        j_36 = j_45;
        off_29 = j_35;
        off_28 = ten_1[off_29] + j_36;
        off_35 = j_42 + 7 + j_45;
        func1[off_28] = func1[off_28] + t_1[off_35];
      }
    }
  }

}