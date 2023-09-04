#include <stdint.h>

static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y);
static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y)
{
  for (int32_t i = 0; i <= 3; ++i)
    y[i] = x[i] + y[i];
}

void mykernel(double const *__restrict__ func0, double *__restrict__ func1, int32_t const *__restrict__ ten, int32_t const *__restrict__ ten_0, int32_t const *__restrict__ map0, int32_t const *__restrict__ map1)
{
  double t_0[4];
  double t_1[4];

  for (int32_t i_0 = 0; i_0 < 3; ++i_0) {  // loop over cells
    for (int32_t i_4 = 0; i_4 < 2; ++i_4) {  // loop over cell dofs
      off_0 = layout0[i_0] + i_4;
      t_0[i_4] = func0[off_0];
    }
    for (int32_t i_5 = 0; i_5 < 2; ++i_5) {  // loop over vertices in closure
      for (int32_t i_6 = 0; i_6 < 1; ++i_6) {  // loop over vertex dofs
        off_1 = map0[i_0 * 2 + i_5];
        off_2 = layout1[off_1] + i_6;
        t_0[i_5 + 2 + i_6] = func0[off_2];
      }
    }


    // ignore below



    {
      int32_t const i_7 = 0;

      j_16 = i_7;
      for (int32_t i_8 = 0; i_8 <= 1; ++i_8)
      {
        j_19 = i_8;
        j_15 = j_0;
        off_12 = j_15 + j_16;
        j_11 = map0[off_12];
        j_12 = j_19;
        off_9 = j_11;
        off_8 = ten[off_9] + j_12;
        off_14 = j_16 * 2 + j_19;
        t_1[off_14] = 0.0;
      }
    }
    for (int32_t i_9 = 0; i_9 <= 1; ++i_9)
    {
      j_18 = i_9;
      {
        int32_t const i_10 = 0;

        j_20 = i_10;
        j_17 = j_0;
        off_13 = j_17 * 2 + j_18;
        j_13 = map1[off_13];
        j_14 = j_20;
        off_11 = j_13;
        off_10 = ten_0[off_11] + j_14;
        off_15 = j_18 + 2 + j_20;
        t_1[off_15] = 0.0;
      }
    }
    dummy_kernel(&(t_0[0]), &(t_1[0]));
    {
      int32_t const i_11 = 0;

      j_26 = i_11;
      for (int32_t i_12 = 0; i_12 <= 1; ++i_12)
      {
        j_29 = i_12;
        j_25 = j_0;
        off_20 = j_25 + j_26;
        j_21 = map0[off_20];
        j_22 = j_29;
        off_17 = j_21;
        off_16 = ten[off_17] + j_22;
        off_22 = j_26 * 2 + j_29;
        func1[off_16] = func1[off_16] + t_1[off_22];
      }
    }
    for (int32_t i_13 = 0; i_13 <= 1; ++i_13)
    {
      j_28 = i_13;
      {
        int32_t const i_14 = 0;

        j_30 = i_14;
        j_27 = j_0;
        off_21 = j_27 * 2 + j_28;
        j_23 = map1[off_21];
        j_24 = j_30;
        off_19 = j_23;
        off_18 = ten_0[off_19] + j_24;
        off_23 = j_28 + 2 + j_30;
        func1[off_18] = func1[off_18] + t_1[off_23];
      }
    }
  }

}
