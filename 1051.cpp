#include<stdio.h>	

int main()
{
	int square[51][51];

	int col, row;
	int i, j, k, max;
	int result, result_n = 1;;

	scanf("%d%d", &col, &row);

	if (col >= row)
		max = row;
	else
		max = col;


	for (i = 0; i< col; i++)
	{
		for (j = 0; j< row; j++)
		{
			scanf("%1d", &square[i][j]);
		}
	}

	for (k = max; k >= 1; k--)
	{
		for (i = 0; i <= col - k; i++)
		{
			for (j = 0; j <= row - k; j++)
			{
				if (square[i][j] == square[i + k - 1][j])
				{
					if (
					square[i][j] == square[i][j + k - 1])
					{
						if (square[i][j] == square[i + k - 1][j + k - 1])
						{
							result = k;
							result_n = 0;
							break;
						}
					}
				}

			}
			if (result_n == 0)
				break;
		}
		if (result_n == 0)
			break;
	}

	printf("%d", result*result);
}