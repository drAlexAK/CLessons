#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int x;
    int type;
} POINT;

typedef struct{
    int x;
    int inclusion;
    int index;
} DOT;

int compPoint(const void *s1, const void *s2);
int compDotValue(const void *s1, const void *s2);
int compDotIndex(const void *s1, const void *s2);

int main()
{
    int iLine, iPoint;

    scanf("%d %d",&iLine, &iPoint);

    DOT aPoint[iPoint];
    POINT aLine[iLine * 2];

    for(int i = 0; i < iLine * 2; i += 2){
        scanf("%d %d", &aLine[i].x, &aLine[i+1].x);

        if ( aLine[i].x > aLine[i+1].x ) {
            aLine[i].type = -1;
            aLine[i + 1].type = 1;
        } else{
            aLine[i + 1].type = -1;
            aLine[i].type = 1;
        }

    }

    for(int i = 0; i < iPoint; i++){
        scanf("%d", &aPoint[i].x);
        aPoint[i].index = i;
        aPoint[i].inclusion = 0;
    }

    qsort(aPoint, iPoint, sizeof(DOT), compDotValue);
    qsort (aLine, iLine * 2, sizeof(POINT), compPoint);

    int count = 0;
    int k = 0;
    int delayMinus = 0;

    for (int i = 0; i < iPoint; i++ ) {
        if (aPoint[i].x < aLine[0].x) continue;          // skip out of skope
        if ( aPoint[i].x > aLine[iLine * 2 - 1].x) break; // skip next

        for ( ;k < iLine * 2; k++){
            if ((aPoint[i].x < aLine[k].x) || (iPoint - 1 == i)) {
                aPoint[i].inclusion = count ;
                count += delayMinus;
                delayMinus = 0;
                break;
            }
            if (aLine[k].x == aPoint[i].x)
            {
                if (aLine[k].type == 1)
                    count++;
                else
                    delayMinus -= 1;
            }
            else count += aLine[k].type;
        }
    }

    qsort(aPoint, iPoint, sizeof(DOT), compDotIndex);

    for(int i = 0; i < iPoint; i++){
        printf("%d ",aPoint[i].inclusion);
    }


    return 0;
}

int compPoint(const void *s1, const void *s2){
    POINT *p1 = (POINT*) s1;
    POINT *p2 = (POINT*) s2;

    return ((p1->x) - (p2->x));
}

int compDotValue(const void *s1, const void *s2) {
    DOT *p1 = (DOT *) s1;
    DOT *p2 = (DOT *) s2;

    return ((p1->x) - (p2->x));
}

int compDotIndex(const void *s1, const void *s2) {
    DOT *p1 = (DOT *) s1;
    DOT *p2 = (DOT *) s2;

    return ((p1->index) - (p2->index));
}
