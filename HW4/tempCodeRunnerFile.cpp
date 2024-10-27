 double temp_01 = m[0][1];
    for (int i = 0; i < 6; i++)
    {
        m[0][i] -= (temp_01*(m[1][i] / m[1][1]));
    }
    