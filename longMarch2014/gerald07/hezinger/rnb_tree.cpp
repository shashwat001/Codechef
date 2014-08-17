#include"rnb_tree.h"


inline void rotate(rnb_node rot_child, rnb_node rot_parent)
// Rotate such that rot_child becomes the parent of rot_parent.
// Prec.: rot_child is a child of rot_parent.
{
// determine the direction dir of the rotation
int dir = (rot_parent->child rnb_left] == rot_child) ? rnb_right : rnb_left
// subtree which changes sides
rnb_tree middle = rot_child->child dir]
// fix middle tree
rot_parent->child 1-dir] = middle
if(middle) middle->par = rot_parent
// fix parent field of rot_child
rot_child->par = rot_parent->par
if(rot_child->par)
if(rot_child->par->child rnb_left] == rot_parent)
rot_child->par->child rnb_left] = rot_child
else
rot_child->par->child rnb_right] = rot_child
// fix parent field of rot_parent
rot_child->child dir] = rot_parent
rot_parent->par = rot_child
}

void rnb_node_struct::isolate()
// Make this node an isolated node.
// Prec.: this != nil
{
// adjust child pointer of parent if it exists
if(par)
if(par->child rnb_left] == this)
par->child rnb_left] = nil
else
par->child rnb_right] = nil
}
// adjust parent pointers of children if they exist
if(child rnb_left]) child rnb_left]->par = nil
if(child rnb_right]) child rnb_right]->par
}

rnb_tree rnb_node_struct::find_root()
// returns the root of the tree containing this node.
// Prec.: this != nil
{
for(rnb_node aux = this aux->par aux = aux->par)
return aux
}



rnb_node rnb_node_struct::sub_pred()
// returns the predecessor of this node in the subtree rooted at this node
// or nil if it does not exist
// Prec.: this != nil
{
// handle the nil case first
if(!child rnb_left]) return nil
}
// find the last node with no right child in the left subtree of u
for(rnb_node aux = child rnb_left] aux->child rnb_right]
aux = aux->child rnb_right])
return au



