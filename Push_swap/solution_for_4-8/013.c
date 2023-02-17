#include "../Libft/libft.h"
#define AND &&
#define DO &&
#define OR |
#define NOT !
#define IS ==
#define EQUAL ==
#define PRINT ft_printf
#define IF

int moves = 0;
void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort_array(int *array_of_numbers, int *array_of_indexes, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		i = len - 1;
		while (i > j)
		{
			if (array_of_numbers[j] < array_of_numbers[i])
			{
				swap_array(array_of_numbers + j, array_of_numbers + i);
				swap_array(array_of_indexes + j, array_of_indexes + i);
			}
			i--;
		}
		j++;
	}
}

void check_repetetive_numbers(int *array, int len)
{
	int i = 0;
	int j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
			{
				printf("Error: there is repetetive number\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

// struct
typedef struct number
{
	int value;
	int index; // where it should go
} num;

typedef struct stack
{
	num *array_of_nums;
	int lenght;
} stack;

// functions
//  rotate (up)
int rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[0];
		ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[list->lenght - 1] = tmp;
		return (1);
	}
	return (0);
}

// reverse rotate (down)
int reverse_rotate(stack *list)
{
	if (list->lenght > 1)
	{
		num tmp = list->array_of_nums[list->lenght - 1];
		ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
		list->array_of_nums[0] = tmp;
		return (1);
	}
	return (0);
}

// push
int push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest); // down
		dest->array_of_nums[0] = tmp;
		return (1);
	}
	else
	{
		printf("\n\"verify src len in push\"\n");
		return (0);
	}
}

// swap
int swap(stack *X)
{
	num tmp = X->array_of_nums[0];
	X->array_of_nums[0] = X->array_of_nums[1];
	X->array_of_nums[1] = tmp;
	return (1);
}

num *max(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == X->lenght - 1)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

num *min(stack *X)
{
	int i = 0;
	while (i < X->lenght)
	{
		if (X->array_of_nums[i].index == 0)
			return (X->array_of_nums + i);
		i++;
	}
	return (NULL);
}

int get_distance(num *array_of_nums)
{
	return (array_of_nums[0].index + 2 * array_of_nums[1].index + array_of_nums[2].index);
}

void sort_3(stack *X, char c)
{
	int i = 0;
	if (X->lenght <= 1)
		printf("\nverify length in sort\n");
	if (X->lenght > 1 && X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
	{
		printf("s%c ", c);
		swap(X);
		moves++;
	}
	if (X->lenght > 2)
	{
		int n = get_distance(X->array_of_nums);
		//	printf("\nn: %d\n", n);
		if (n == 3)
		{
			printf("r%c ", c);
			rotate(X);
			moves++;
		}
		if (n == 5)
		{
			printf("rr%c ", c);
			reverse_rotate(X);
			moves++;
		}
		if (X->array_of_nums[0].index == X->array_of_nums[1].index + 1)
		{
			printf("s%c ", c);
			swap(X);
		}
	}
}

// be aware that a lenght change all the time
void sort1(stack *A, stack *B, int len)
{
	printf("    len/4: %d\n", len / 4);
	printf("    len/2: %d\n", len / 2);
	printf("3*(len/4): %d\n", 3 * (len / 4));
	printf("      len: %d\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("\n1st while loop\n");
	while (B->lenght < len / 2)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2nd while loop\n");
	while (B->lenght < len)
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 4) || A->array_of_nums[0].index < len / 4)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
}
void sort2(stack *A, stack *B, int len)
{
	printf("01*(len/16): %d\n", len / 16);
	printf("02*(len/16): %d\n", 2 * (len / 16));
	printf("03*(len/16): %d\n", 3 * (len / 16));
	printf("04*(len/16): %d\n", 4 * (len / 16));
	printf("05*(len/16): %d\n", 5 * (len / 16));
	printf("06*(len/16): %d\n", 6 * (len / 16));
	printf("07*(len/16): %d\n", 7 * (len / 16));
	printf("08*(len/16): %d\n", 8 * (len / 16));
	printf("09*(len/16): %d\n", 9 * (len / 16));
	printf("10*(len/16): %d\n", 10 * (len / 16));
	printf("11*(len/16): %d\n", 11 * (len / 16));
	printf("12*(len/16): %d\n", 12 * (len / 16));
	printf("13*(len/16): %d\n", 13 * (len / 16));
	printf("14*(len/16): %d\n", 14 * (len / 16));
	printf("15*(len/16): %d\n", 15 * (len / 16));
	printf("16*(len/16): %d\n\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	printf("\n1st while loop\n");
	while (B->lenght < len / 4) // 3/8 -> 5/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 8) && A->array_of_nums[0].index < 5 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2nd while loop\n");
	while (B->lenght < len / 2) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n3rd while loop\n");
	while (B->lenght < 3 * (len / 4)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 8 && A->array_of_nums[0].index < 7 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n4th while loop\n");
	while (B->lenght < len) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 7 * (len / 8) || A->array_of_nums[0].index < len)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
}

void sort3(stack *A, stack *B, int len)
{
	printf("len: %d\n", len);
	printf("01*(len/3): %d\n", len / 3);
	printf("02*(len/3): %d\n", 2 * (len / 3));
	printf("03*(len/3): %d\n", 3 * (len / 3));

	int ra = 0;
	int rb = 0;
	int p = 0;

	printf("\n1st while loop\n");
	float min = 14 * (len / 27);
	float max = 14 * (len / 27);

	float len2;
	len2 = 0;
	while (min > 0 && max < len)
	{
		min -= (len / 27);
		max += (len / 27);
		len2 = (int)max - (int)min;
		while (B->lenght < (int)len2) // 3/8 -> 5/8
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index <= max)
			{
				if (A->array_of_nums[0].index >= len / 2)
					rb++;
				moves += push(A, B);
				printf("p ");
				if (rb)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			if (ra && rb)
			{
				printf("rr ");
				moves++;
			}
			else
			{
				ra &&printf("ra ");
				rb &&printf("rb ");
				moves += (ra + rb);
			}
		}
	}
	printf("\n\non exit:\nmin:%f\nmax:%f\nlen: %d\n", min, max, len);
}

void sort4(stack *A, stack *B, int len)
{
	// printf("01*(len/16): %d\n", len / 16);
	// printf("02*(len/16): %d\n", 2 * (len / 16));
	// printf("03*(len/16): %d\n", 3 * (len / 16));
	// printf("04*(len/16): %d\n", 4 * (len / 16));
	// printf("05*(len/16): %d\n", 5 * (len / 16));
	// printf("06*(len/16): %d\n", 6 * (len / 16));
	// printf("07*(len/16): %d\n", 7 * (len / 16));
	// printf("08*(len/16): %d\n", 8 * (len / 16));
	// printf("09*(len/16): %d\n", 9 * (len / 16));
	// printf("10*(len/16): %d\n", 10 * (len / 16));
	// printf("11*(len/16): %d\n", 11 * (len / 16));
	// printf("12*(len/16): %d\n", 12 * (len / 16));
	// printf("13*(len/16): %d\n", 13 * (len / 16));
	// printf("14*(len/16): %d\n", 14 * (len / 16));
	// printf("15*(len/16): %d\n", 15 * (len / 16));
	// printf("16*(len/16): %d\n", len);
	int ra = 0;
	int rb = 0;
	int p = 0;
	float min; // for 2n
	float max; // for 2n
	float len2 = 0;
	float len3 = 0;

#if 0
	if (len % 2 == 0)
	{
		min = 0;			  // for 2n
		max = (float)len / 2; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len / 2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
		while (B->lenght < len)
			moves += push(A,B);
	}
#elif 0 // 183 moves
	if (len % 4 == 0)
	{
		min = len / 4;			  // for 2n
		max = 3 * (float)len / 4; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
		min = 0;		  // for 2n
		max = (float)len; // for 2nd
		len2 = max - min;
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
	}
#elif 1
	if (len % 2 == 0)
	{
		int len3 = len / 2;
		if (len3 % 2 == 0)
		{
			
			min = (float)len / 2 - len3 / 2; // for 2n
			max = (float)len / 2 + len3 / 2; // for 2nd

			len2 = max - min;
			printf("\nstart 1:\nA.lenght = %d\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n", A->lenght, B->lenght, min, max, len2);
			//	exit(0);
			// the start
			while (B->lenght < len2)
			{
				ra = 0;
				rb = 0;
				if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
				{
					moves += push(A, B);
					printf("p ");
					if (B->array_of_nums[0].index >= (min + max) / 2) // hna kayna l3eyba
						rb = rotate(B);								  // rotate cna ruturn 0 if len is les than 2
				}
				else
					ra = rotate(A);
				ra &&rb &&printf("rr ") && moves++;
				ra && !rb && printf("ra ") && moves++;
				rb && !ra && printf("rb ") && moves++;
			}
		}
		else
			printf("\n\"split to two\"\n");

		// the end
		min = 0;		  // for 2n
		max = (float)len; // for 2nd
		len2 = max - min;
		printf("\n\nstart 2:\nA.lenght = %d\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n", A->lenght, B->lenght, min, max, len2);
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
	}
#elif 1
	if (len % 2 == 0)
	{
		len2 =
			min = len / 4;		  // for 2n
		max = 3 * (float)len / 4; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
	}
#elif 1
	if (len % 2 == 0)
	{

		min = len / 4;			  // for 2n
		max = 3 * (float)len / 4; // for 2nd
		len2 = max - min;
		printf("\nstart:\nB.lenght = %d\nmin = %f\nmax = %f\nlen2 = %f\n\n\n", B->lenght, min, max, len2);
		while (B->lenght < len2)
		{
			ra = 0;
			rb = 0;
			if (A->array_of_nums[0].index >= min && A->array_of_nums[0].index < max)
			{
				moves += push(A, B);
				printf("p ");
				if (B->array_of_nums[0].index >= (min + max) / 2)
					rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
			}
			else
				ra = rotate(A);
			ra &&rb &&printf("rr ") && moves++;
			ra && !rb && printf("ra ") && moves++;
			rb && !ra && printf("rb ") && moves++;
		}
	}
#else
	printf("\n1st while loop\n");
	while (B->lenght < len / 4) // 3/8 -> 5/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 3 * (len / 8) && A->array_of_nums[0].index < 5 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n2nd while loop\n");
	while (B->lenght < len / 2) // 1/4 -> 3/4
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 4 && A->array_of_nums[0].index < 3 * (len / 4))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate cna ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n3rd while loop\n");
	while (B->lenght < 3 * (len / 4)) // 1/8 -> 7/8
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= len / 8 && A->array_of_nums[0].index < 7 * (len / 8))
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
	printf("\n4th while loop\n");
	while (B->lenght < len) // 0 -> 1
	{
		ra = 0;
		rb = 0;
		if (A->array_of_nums[0].index >= 7 * (len / 8) || A->array_of_nums[0].index < len)
		{
			if (A->array_of_nums[0].index >= len / 2)
				rb++;
			moves += push(A, B);
			printf("p ");
			if (rb)
				rb = rotate(B); // rotate can ruturn 0 if len is les than 2
		}
		else
			ra = rotate(A);
		if (ra && rb)
		{
			printf("rr ");
			moves++;
		}
		else
		{
			ra &&printf("ra ");
			rb &&printf("rb ");
			moves += (ra + rb);
		}
	}
#endif
}

int main(void)
{
	int i;
	int const_array[] = {221, 213, 376, 2, 23, 242, 469, 299, 384, 185, 457, 175, 173, 380, 200, 363, 309, 191, 326, 254, 156, 369, 50, 208, 418, 112, 222, 147, 123, 414, 46, 110, 183, 495, 216, 115, 387, 119, 77, 70, 129, 419, 460, 385, 93, 225, 21, 281, 334, 366, 178, 186, 18, 231, 261, 331, 269, 248, 456, 289, 135, 291, 138, 151, 307, 393, 412, 108, 201, 56, 245, 404, 224, 378, 388, 27, 214, 421, 415, 240, 89, 122, 230, 139, 482, 58, 413, 96, 219, 353, 337, 298};
	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));
	check_repetetive_numbers(const_array, len);

	// copy const_array to the heap in array_of_numbers
	ft_memcpy(array_of_numbers, const_array, sizeof(const_array));

	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// setup stack A and B
	stack *A = ft_calloc(1, sizeof(stack));
	stack *B = ft_calloc(1, sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;

	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	// feed numbers
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}

	printf("\n=========== MAIN ===========\n");
	sort_array(array_of_numbers, array_of_indexes, len);
	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	// sort_3(A, 'a');
	// sort1(A, B, len);
	// sort2(A, B, len);
	sort4(A, B, len);

	printf("\n\nafter sorting\nA: \n");
	i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].value);
	// printf("\nin:");
	i = 0;
	int spliter = 4;
	while (i < A->lenght)
	{
		printf("%4d ", A->array_of_nums[i++].index);
		if (i % (len / spliter) == 0)
			printf("\n");
	}
	printf("\nB: \n");
	// i = 0;
	// while (i < B->lenght)
	// {
	// 	printf("%4d ", B->array_of_nums[i++].value);
	// 	if (i % (len / 32) == 0)
	// 		printf("\n");
	// }
	// printf("\nin:\n");
	i = 0;
	while (i < B->lenght)
	{
		printf("%4d ", B->array_of_nums[i++].index);
		if (i % (len / spliter) == 0)
			printf("\n");
	}
	printf("\n\n");
	printf("moves : %d\n\n", moves);

	return (0);
}