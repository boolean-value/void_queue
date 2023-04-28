#include "queue.h"

int main()
{
    //inserting ints
    int num0 = 10;
    int num1 = 55;
    int num2 = 87;

    queue_t * queue= queue_create();
    if(NULL == queue)
    {
        goto ERROR;
    }
    //enqueuing each number
    queue_enqueue(queue, &num0);
    queue_enqueue(queue, &num1);
    queue_enqueue(queue, &num2);

    printf("\nPRINTING FULL LIST...");
    print_integer_queue(queue);

    int sampl = 807;
    int *result = NULL;

    //getting the nth item in the queue
    result = queue_get_nth_item(queue, 2);
    printf("\nTHE 3RD ITEM IN THE LIST IS %d\n", *result);


    if(true == queue_contains(queue, &sampl))
    {
        printf("\n%d IS IN THE LIST\n", sampl);
    }
    else
    {
        printf("\n%d IS NOT IN THE LIST\n", sampl);
    }

    //removing and item from the queue
    int val_to_remove = 87;
    int_queue_remove(queue, &val_to_remove);

    printf("\nPRINTING FULL LIST...");
    print_integer_queue(queue);

    remove_all(queue);

    queue_destroy(queue);
    queue = NULL;

// inserting strings
    queue_t *re_queue = queue_create();
    if(NULL == re_queue)
    {
        goto ERROR;
    }
    const char * word = "brent";
    const char * word1 = "davis";
    const char * word2 = "smith";
    const char * word3 = "bill";
    const char * word4 = "davidson";
    const char * word5 = "harley";
    const char * word6 = "bilal";
    const char * word7 = "dirk";
    const char * word8 = "sammy";

    queue_enqueue(re_queue, (char*)word);
    queue_enqueue(re_queue, (char*)word1);
    queue_enqueue(re_queue, (char*)word2);
    queue_enqueue(re_queue, (char*)word3);
    queue_enqueue(re_queue, (char*)word4);
    queue_enqueue(re_queue, (char*)word5);
    queue_enqueue(re_queue, (char*)word6);
    queue_enqueue(re_queue, (char*)word7);
    queue_enqueue(re_queue, (char*)word8);

    printf("\nPRINTING FULL LIST...");
    print_char_queue(re_queue);

    char_queue_remove(re_queue, (char*)word4);

    printf("\nPRINTING FULL LIST AFTER REMOVING davidson...");
    print_char_queue(re_queue);

    void * removed_string = NULL;
    removed_string = queue_get_nth_item(re_queue, 4);
    printf("THE 5ND ITEM  IN THE LIST IS %s\n", (char*)removed_string);


    queue_dequeue(re_queue);

    printf("\nPRINTING FULL LIST AFTER DEQUEUE...");
    print_char_queue(re_queue);

    remove_all(re_queue);

    queue_destroy(re_queue);
    re_queue = NULL;
    goto SUCCESS;


ERROR:
    exit(EXIT_FAILURE);

SUCCESS:
    exit(EXIT_SUCCESS);
}