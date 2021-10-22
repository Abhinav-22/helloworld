#include <stdio.h>

int p_no, r_no, avail[100], work[100], SAFE_SEQ[100], s_c = 0, p_c;
struct process
{
    int MAX[100], alloc[100], need[100], flg;
} p[100];

void max_matrix()
{
    int i, j;
    printf("Enter the MAX matrix: ");
    for (i = 0; i < p_no; ++i)
    {
        for (j = 0; j < r_no; ++j)
        {
            scanf("%d", &p[i].MAX[j]);
        }
    }
}

void available()
{
    int i;
    printf("Enter the available matrix: ");
    for (i = 0; i < r_no; i++)
    {
        scanf("%d", &avail[i]);
    }
}

void allocation_matrix()
{
    int i, j;
    printf("Enter the ALLOCATION matrix: ");
    for (i = 0; i < p_no; i++)
    {
        for (j = 0; j < r_no; j++)
        {
            scanf("%d", &p[i].alloc[j]);
        }
    }
}

void print_table()
{
    int i, j;
    printf("\n");
    printf("ID       Allocation          Max            Need  ");
    printf("\n");
    for (i = 0; i < p_no; i++)
    {
        printf("p%d          ", i);
        for (j = 0; j < r_no; j++)
        {
            printf("%d ", p[i].alloc[j]);
        }
        printf("          ");
        for (j = 0; j < r_no; j++)
        {
            printf("%d ", p[i].MAX[j]);
        }
        printf("          ");
        for (j = 0; j < r_no; j++)
        {
            printf("%d ", p[i].need[j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, k, flag = 1, count = 0, present;
    printf("Enter the number of processes: ");
    scanf("%d", &p_no);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r_no);
    max_matrix();
    allocation_matrix();
    available();

    for (i = 0; i < r_no; i++)
        work[i] = avail[i];

    for (i = 0; i < p_no; i++)
    {
        for (j = 0; j < r_no; j++)
        {
            p[i].need[j] = p[i].MAX[j] - p[i].alloc[j];
        }
    }

    for (i = 0; i < p_no; i++)
    {
        p[i].flg = 0;
    }
    print_table();
    while (count < p_no)
    {

        present = count;
        for (i = 0; i < p_no; i++)
        {
            flag = 0;
            if (p[i].flg == 0)
            {
                for (j = 0; j < r_no; j++)
                {
                    if (p[i].need[j] > work[j])
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    SAFE_SEQ[s_c] = i;
                    s_c++;
                    p[i].flg = 1;

                    count++;
                    for (j = 0; j < r_no; j++)
                    {
                        work[j] += p[i].alloc[j];
                    }
                }
            }
        }
        if (present == count)
        {
            printf("UNSAFE STATE");
            break;
        }
    }
    if (p_no == s_c)
    {
        printf("\nSAFE STATE.The safe sequence is: ");
        for (k = 0; k < s_c - 1; k++)
        {
            printf(" %d-->", SAFE_SEQ[k]);
        }
        printf(" %d", SAFE_SEQ[k]);
    }
    else
    {
        printf("\nUNSAFE STATE.The sequence is: ");
        for (k = 0; k < s_c - 1; k++)
        {
            printf(" %d-->", SAFE_SEQ[k]);
        }
        printf(" %d", SAFE_SEQ[k]);
    }

    return 0;
}
