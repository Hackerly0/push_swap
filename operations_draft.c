// void insert_at_head(t_list** head_ref, t_list* new_node) {
//     t_list* temp = *head_ref;//     new_node->next = temp;
//     new_node->prev = NULL;//     if (temp != NULL) {
//         temp->prev = new_node;
//     }//     *head_ref = new_node;
// }// void insert_at_tail(t_list** tail_ref, t_list* new_node) {
//     t_list* tail = *tail_ref;
//     new_node -> prev = tail;
//     new_node -> next = NULL;//     if (tail != NULL) {
//         tail->next = new_node;
//     }//     *tail_ref = new_node;
// }// void delete_node(t_list** head_ref, t_list** tail_ref, t_list* node_to_delete) {
//     // If the list is empty or node_to_delete is NULL, do nothing
//     if (*head_ref == NULL || node_to_delete == NULL) {
//         return;
//     }//     // If the node to delete is the head of the list
//     if (*head_ref == node_to_delete) {
//         *head_ref = node_to_delete->next;
//     }//     // If the node to delete is the tail of the list
//     if (*tail_ref == node_to_delete) {
//         *tail_ref = node_to_delete->prev;
//     }//     // If node_to_delete is not the last node, update the next node's prev pointer
//     if (node_to_delete->next != NULL) {
//         node_to_delete->next->prev = node_to_delete->prev;
//     }//     // If node_to_delete is not the first node, update the previous node's next pointer
//     if (node_to_delete->prev != NULL) {
//         node_to_delete->prev->next = node_to_delete->next;
//     }//     // Free the memory of the deleted node
//     free(node_to_delete);
// }// void display_list(t_list **head_ref) {
//     t_list *temp = *head_ref;
//     while(temp != NULL){
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");// }// int main() {
	
//     t_list* node3 = (t_list*) malloc(sizeof(t_list));
//     t_list* node2 = (t_list*) malloc(sizeof(t_list));
//     t_list* node1 = (t_list*) malloc(sizeof(t_list));//     node1->data = 1;
//     node2->data = 2;
//     node3->data = 3;//     node1->next = node2;
//     node1->prev = NULL;//     node2->next = node3;
//     node2->prev = node1;//     node3->next = NULL;
//     node3->prev = node2;//     display_list(&node1);//     free(node1);
//     free(node2);
//     free(node3);// }


// data rotation, shifts lists data by 1.
static void	ra(t_list **headA)
{
	t_list	*head;
	int		temp;

	if (headA == NULL || *headA == NULL)
		return;
	head = *headA;
	temp = head -> data;
	while (head -> next != NULL)
	{
		head->data = head->next->data;
		head = head->next;
	}
	head -> data = temp;
}

// pointer rotation, shifts lists node by 1,
// taking the advantage of linked lists and
// better for performance.
void    ra(t_list **headA)
{
	t_list	*head;
	t_list	*tail;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	head = *headA;
	tail = head;    // Traverse to the last node
	while (tail->next != NULL)
		tail = tail->next;
	// Update pointers to perform the rotation
	*headA = head->next; // Move the head to the second node
	head->next = NULL;   // Detach the original head
	tail->next = head;   // Attach the original head to the tail
}

void    rra(t_list **headA)
{
	t_list	*head;
	t_list	*tail;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return;
	head = *headA;
	tail = head;
	while (tail->next->next != NULL)
		tail = tail -> next;
	*headA = tail -> next;
	tail -> next -> next = head;
	tail -> next = NULL;
}

void	pa(t_list **headA, t_list **headB)
{
	t_list	*topB;

	if (headB == NULL || *headB == NULL)
		return;
	topB = *headB;
	// make the head B pointer points to the next element
	// in the list (topB -> next is the next element)
	// so that we exclude the element from the list.
	*headB = topB->next;    // made the first element in B to point to head of A
	// then assign the head A pointer to the new element
	// making it the new head.
	topB->next = *headA;
	*headA = topB;
}

// typedef struct s_node
// {
// 	int		indx;
// 	int		cost;
// 	long	data;
// 	bool	abv_med;
// 	bool	cheap;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// 	struct s_node	*tar;
// }	t_node;

/*The indx var is for the index of the node, we need this in order to find the cheapest element.
  The cost var is for measuring the cost of pushing this element to the other stack.
  The data var is the number that is contained in this node.
  The abv_med is to check if the element is above median node, this is because if the more above median
    the cheaper it is to push.
  The cheap is check weather this node is the cheapest to push or not.
  The next & prev pointers is for the circular linked list.
  The tar pointer is the target node in the other stack (for the algorithm).*/
