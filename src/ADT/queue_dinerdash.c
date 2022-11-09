#include "queue_dinerdash.h"

void CreateQueueFood(QueueFood *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

void CreateQueueCook(QueueCook *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyFood(QueueFood q)
{
    return((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isEmptyCook(QueueCook q)
{
    return((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

int lengthFood(QueueFood q)
{
    if (isEmptyFood(q)){
        return 0;
    } else{
        if (IDX_HEAD(q) > IDX_TAIL(q)){
            return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
        } else {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

int lengthCook(QueueCook q)
{
    if (isEmptyCook(q)){
        return 0;
    } else{
        if (IDX_HEAD(q) > IDX_TAIL(q)){
            return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
        } else {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

void enqueueFood(QueueFood *q, Food val)
{
    if (isEmptyFood(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == CAPACITY - 1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }   
    }
    TAIL(*q) = val;
}

void dequeueFood(QueueFood *q)
{   
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*q) == CAPACITY - 1) {
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}

void enqueueCook(QueueCook *q, Cook val)
{
    if (isEmptyCook(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == CAPACITY - 1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }   
    }
    TAIL(*q) = val;
}

void dequeueCook(QueueCook *q)
{   
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*q) == CAPACITY - 1) {
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}