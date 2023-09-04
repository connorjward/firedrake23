#include <stdint.h>

static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y);
static void dummy_kernel(double const *__restrict__ x, double *__restrict__ y)
{
  for (int32_t i = 0; i <= 9; ++i)
    y[i] = x[i] + y[i];
}

void mykernel(double const *__restrict__ func0, double *__restrict__ func1, int32_t const *__restrict__ ten, int32_t const *__restrict__ ten_0, int32_t const *__restrict__ ten_1, int32_t const *__restrict__ map0, int32_t const *__restrict__ map1, int32_t const *__restrict__ map2)
{

  // to store the "packed" data
  double t_0[10];

  // loop over cells
  for (int32_t i_0 = 0; i_0 < 2; ++i_0) {
    // pack cell DoFs
    t_0[0] = func0[layout0[i_0]];

    // pack edge DoFs
    for (int32_t i_5 = 0; i_5 < 3; ++i_5) {  // loop over edges
      for (int32_t i_6 = 0; i_6 < 2; ++i_6) {  // loop over edge DoFs
        j_3 = map1[i_0 * 3 + i_5];  // select the right edge
        t_0[i_5*2 + i_6 + 1] = func0[layout1[j_3] + i_6];  // pack DoF
      }
    }

    // pack vertex DoFs
    for (int32_t i_7 = 0; i_7 < 3; ++i_7) {  // loop over vertices
      j_5 = map2[i_0 * 3 + i_7];  // select the right vertex
      t_0[i_7 + 7] = func0[layout2[j_5]];  // pack DoF
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
