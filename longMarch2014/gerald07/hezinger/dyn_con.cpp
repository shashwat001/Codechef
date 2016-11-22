#include<iostream>
#include<stdlib.h>

enum rnb_dir 
{
	rnb_left=0, 
	rnb_right=1
};

#define nil 0
#define true 1
#define false 0


class rnb_node_struct;
typedef rnb_node_struct* rnb_node;
typedef rnb_node rnb_tree;

class rnb_node_struct
{
	public:
	rnb_node_struct() {par = child [0] = child [1] = nil; prio = random(); }
	virtual ~rnb_node_struct() { isolate(); }

	rnb_node find_root();
	rnb_node sub_pred();
	rnb_node sub_succ();
	rnb_node pred();
	rnb_node succ();
	rnb_node cyclic_pred() { return (this == first()) ? last() : pred() ;}
	rnb_node cyclic_succ() { return (this == last()) ? first() : succ(); }
	rnb_node first();
	rnb_node last();
	friend int smaller(rnb_node u, rnb_node v);
	friend rnb_tree rnb_join(rnb_tree t1, rnb_tree t2, rnb_node dummy);
	friend void split(rnb_node at, int where, rnb_tree& t1, rnb_tree& t2,rnb_node dummy);
	friend void traverse(rnb_tree t);
	protected:
	rnb_node par;
	rnb_node child[2];
	long prio;

	friend void rotate(rnb_node rot_child, rnb_node rot_parent);
	virtual void after_rot() { }
	virtual void init() { }
	virtual void isolate();
};


inline void rotate(rnb_node rot_child, rnb_node rot_parent)
{
	int dir = (rot_parent->child [rnb_left] == rot_child) ? rnb_right : rnb_left;
	rnb_tree middle = rot_child->child [dir];
	rot_parent->child [1-dir] = middle;
	if(middle) 
		middle->par = rot_parent;
	rot_child->par = rot_parent->par;
	if(rot_child->par)
		if(rot_child->par->child [rnb_left] == rot_parent)
			rot_child->par->child [rnb_left] = rot_child;
		else
			rot_child->par->child [rnb_right] = rot_child;
	rot_child->child [dir] = rot_parent;
	rot_parent->par = rot_child;
	rot_parent->after_rot();
}

void rnb_node_struct::isolate()
{
	if(par)
		if(par->child [rnb_left] == this)
			par->child [rnb_left] = nil;
		else
			par->child [rnb_right] = nil;
	if(child [rnb_left]) 
		child [rnb_left]->par = nil;
	if(child [rnb_right]) 
		child [rnb_right]->par = nil;
}

rnb_tree rnb_node_struct::find_root()
{
	rnb_node aux;
	for(aux = this; aux->par; aux = aux->par);
	return aux;
}


rnb_node rnb_node_struct::sub_pred()
{
	if(!child [rnb_left]) 
		return nil;
	rnb_node aux;
	for(aux = child [rnb_left]; aux->child [rnb_right];aux = aux->child [rnb_right]);
	return aux;
}


rnb_node rnb_node_struct::sub_succ()
{
	if(!child [rnb_right]) 
		return nil;
	rnb_node aux;
	for( aux = child [rnb_right]; aux->child [rnb_left];aux = aux->child [rnb_left]);
	return aux;
}

rnb_node rnb_node_struct::pred()
{
	rnb_node sub_pr = sub_pred();
	if(sub_pr) 
		return sub_pr;
	if(par)
		if(this == par->child [rnb_right])
			return par;
		else
		{
			for(rnb_node aux = par; aux->par; aux = aux->par)
				if(aux == aux->par->child [rnb_right]) 
					return aux->par;
		}
	return nil;
}


rnb_node rnb_node_struct::succ()
{
	rnb_node sub_s = sub_succ();
	if(sub_s) 
		return sub_s;
	if(par)
		if(this == par->child [rnb_left])
			return par;
		else
		{
			for(rnb_node aux = par; aux->par; aux = aux->par)
				if(aux == aux->par->child [rnb_left]) 
					return aux->par;
		}
	return nil;
}


rnb_node rnb_node_struct::first()
{
	rnb_node last = nil;
	for(rnb_node current = this; current ;current = current->child [rnb_left])
		last = current;
	return last;
}

rnb_node rnb_node_struct::last()
{
	rnb_node last = nil;
	for(rnb_node current = this; current ;current = current->child [rnb_right])
		last = current;
	return last;
}



int smaller(rnb_node u, rnb_node v)
{
	if(!u || !v) return false;
	if(u == v) return false;
	
	int u_height,v_height;
	rnb_node aux_u = u;
	for(u_height= 0; aux_u->par; aux_u = aux_u->par, u_height++);
	rnb_node aux_v = v;
	for(v_height= 0; aux_v->par; aux_v = aux_v->par, v_height++);

	if(aux_u != aux_v) 
		return false;

	int *u_path = new int[u_height];
	int *v_path = new int[v_height];
	int u_i = u_height - 1;
	for(aux_u = u; aux_u->par; aux_u = aux_u->par, u_i--)
	{
		if(aux_u->par->child [rnb_left] == aux_u) 
			u_path [u_[i] = rnb_left;
		else
			u_path [u_[i] = rnb_right;
	}
	int v_i = v_height - 1;
	for(aux_v = v; aux_v->par; aux_v = aux_v->par, v_i--)
	{
		if(aux_v->par->child [rnb_left] == aux_v) 
			v_path [v_[i] = rnb_left;
		else
			v_path [v_[i] = rnb_right;
	}
	int i;
	for( i = 0; ((i<u_height) && (i<v_height)) && (u_path [[i] == v_path [[i]);i++);
	int result;
	if( (i<u_height) && (u_path [[i] == rnb_left) )
		result = true;
	else
		if( (i<v_height) && (v_path [[i] == rnb_right) )
			result = true;
		else	
			result = false;
	delete [] u_path;
	delete [] v_path;
	return result;
}




rnb_tree rnb_join(rnb_tree t1, rnb_tree t2, rnb_node dummy)
{
	if(!t1 || !t2)
	{
		if(t1) 
			return t1;
		if(t2) 
			return t2;
		return nil;
	}
	dummy->par = nil;
	dummy->child [rnb_left] = t1;
	dummy->child [rnb_right] = t2;
	t1->par = dummy;
	t2->par = dummy;
	dummy->init();
	while( (dummy->child [rnb_left]) || (dummy->child [rnb_right]) )
	{
		rnb_node bigger = dummy->child [rnb_left];
		if(dummy->child [rnb_right])
		{
			if(dummy->child [rnb_left])
			{
				if(dummy->child [rnb_right]->prio > dummy->child [rnb_left]->prio)
					bigger = dummy->child [rnb_right];
			}
			else 
				bigger = dummy->child [rnb_right];
		}
		rotate(bigger,dummy);
	}
	dummy->isolate();
	if(t2->par) 
		return t1;
	else
		return t2;
}



void split(rnb_node at, int where, rnb_tree& t1, rnb_tree& t2, rnb_node dummy)
{
	if(!at)
	{
		t1 = nil;
		t2 = nil;
		return;
	}
	dummy->child [rnb_left] = nil;
	dummy->child [rnb_right] = nil;
	if(where != rnb_left)
	{
		rnb_node s = at->sub_succ();
		if(!s)
		{
			at->child [rnb_right] = dummy;
			dummy->par = at;
		}
		else
		{
			s->child [rnb_left] = dummy;
			dummy->par = s;
		}
	}
	else
	{
		rnb_node p = at->sub_pred();
		if(!p)
		{
			at->child [rnb_left] = dummy;
			dummy->par = at;
		}
		else
		{
			p->child [rnb_right] = dummy;
			dummy->par = p;
		}
	}
	dummy->init();
	for(rnb_node u = dummy->par; u; u = dummy->par) 
		rotate(dummy,u);
	t1 = dummy->child [rnb_left];
	t2 = dummy->child [rnb_right];

	dummy->isolate();
}


void traverse(rnb_tree t)
{
	if(t)
	{
		traverse(t->child [rnb_left]);
		traverse(t->child [rnb_right]);
	}
}





class rnbw_node_struct;
typedef rnbw_node_struct* rnbw_node;
typedef rnbw_node rnbw_tree;

class rnbw_node_struct : public rnb_node_struct 
{
	public:
	rnbw_node_struct(int w = 1) : rnb_node_struct() { weight = sub_weight = w;}

	int get_weight() { return weight; }

	int get_subtree_weight() { return sub_weight; }

	void set_weight(int w);

	void add_weight(int a);

	friend rnbw_node rnbw_locate(rnbw_tree t, int w, int& offset);

	rnbw_node parent() { return (rnbw_node) par ;}
	rnbw_node left_child() { return (rnbw_node) child [rnb_left]; }
	rnbw_node right_child() { return (rnbw_node) child [rnb_right]; }
	rnbw_tree find_root() {return (rnbw_tree) rnb_node_struct::find_root(); }
	rnbw_node pred() { return (rnbw_node) rnb_node_struct::pred(); }
	rnbw_node succ() { return (rnbw_node) rnb_node_struct::succ(); }
	friend inline rnbw_tree rnbw_join(rnbw_tree t1, rnbw_tree t2, rnbw_node dummy)
	{ 
		return (rnbw_tree) rnb_join(t1,t2,dummy);
	}


	protected:
	void after_rot();

	void init();

	virtual void isolate();

	private:
	int weight;
	int sub_weight;
};

void rnbw_node_struct::init()
{
	sub_weight = weight;
	if(left_child()) sub_weight += left_child()->sub_weight;
	if(right_child()) sub_weight += right_child()->sub_weight;
}

void rnbw_node_struct::isolate()
{
		for(rnbw_node aux = parent(); aux; aux = aux->parent())
			aux->sub_weight -= sub_weight;
		rnb_node_struct::isolate();
}


void rnbw_node_struct::set_weight(int w)
{
	int w_diff = w - weight;
	sub_weight += w_diff;
	weight = w;

	for(rnbw_node aux = parent(); aux; aux = aux->parent())
		aux->sub_weight +=w_diff;
}


void rnbw_node_struct::add_weight(int a)
{
	sub_weight += a;
	weight += a;
	for(rnbw_node aux = parent(); aux; aux = aux->parent())
		aux->sub_weight += a;
}


rnbw_node rnbw_locate(rnbw_tree t, int w, int& offset)
{
// current node
	rnbw_node curr_node = t;

	int lower = curr_node->left_child() ?curr_node->left_child()->sub_weight : 0;

	int upper = lower + curr_node->weight;
	while(w <= lower || w > upper)
	{
		if(w <= lower)
		{
			curr_node = curr_node->left_child();
			lower -= curr_node->sub_weight;
			if(curr_node->left_child())
				lower += curr_node->left_child()->sub_weight;
			upper = lower + curr_node->weight;
		}
		else
		{
			curr_node = curr_node->right_child();
			lower = upper + curr_node->sub_weight - curr_node->weight;
			if(curr_node->right_child())
				lower -= curr_node->right_child()->sub_weight;
			upper = lower + curr_node->weight;
		}
	}
	offset = w - lower;
}






class dyn_con;
class et_node_struct;

typedef et_node_struct* et_node;
typedef et_node et_tree;



class et_node_struct : public rnbw_node_struct
{
	public:
	et_node_struct(dyn_con * dcp,node v,int my_level = -1,int active = false);
	et_node_struct(et_node en);
	
	node get_corr_node()
	{
		return corr_node;
	}
	
	int is_active()
	{
		return active;
	}
	
	friend et_tree et_link(node u,node v,edge e, int i, dyn_con *dc);
	
	friend void et_cut(edge e,int i,dyn_con *dc);
	
	
	// --- Conversion Functions ---
	et_node parent() { return (et_node) rnbw_node_struct::parent(); }
	et_node left_child() { return (et_node) child [rnb_left]; }
	et_node right_child() { return (et_node) child [rnb_right]; }
	et_tree find_root() { return (et_tree) rnb_node_struct::find_root(); }
	et_node first() { return (et_node) rnb_node_struct::first(); }
	et_node last() { return (et_node) rnb_node_struct::last(); }
	et_node cyclic_succ() { return (et_node) rnb_node_struct::cyclic_succ();}
	et_node cyclic_pred() { return (et_node) rnb_node_struct::cyclic_pred();}
	friend inline et_tree et_join(et_tree t1, et_tree t2, et_node dummy)
	{ return (et_tree) rnb_join(t1,t2,dummy); }
	friend inline et_node et_locate(et_tree et, int w, int& offset)
	{ return (et_node) rnbw_locate(et,w,offset);
	}
	void pass_activity(et_node to);

	friend void change_root(et_tree& et, et_node en, int i, dyn_con* dc);


	
	protected:
	dyn_con *dc;
	node corr_node;
	int level;
	int active;
	edge edge_occ[2];
};


et_node_struct::et_node_struct(dyn_con* dcp, node v, int my_level, int activate): rnbw_node_struct(0)
{
	dc = dcp;
	corr_node = v;
	level = my_level;
	active = activate;
	if(activate) dc->Gp->inf(v)->act_occ [level] = this;
	edge_occ [0] = edge_occ [1] = nil;
}
et_node_struct::et_node_struct(et_node en): rnbw_node_struct(0)
{
	dc = en->dc;
	corr_node = en->corr_node;
	level = en->level;
	active = false;

	edge_occ [0] = edge_occ [1] = nil;
}


void et_node_struct::pass_activity(et_node to)
{
	active = false;
	to->active = true;
	to->set_weight(get_weight());
	set_weight(0);
	dc->Gp->inf(corr_node)->act_occ [level] = to;
}

void change_root(et_tree& et, et_node en, int i, dyn_con* dc)
{
	et_node first_nd = et->first();
	if(en == first_nd) 
		return;
	et_node new_occ = new et_node_struct(en);
	et_node last_nd = et->last();
	if(first_nd->active) 
		first_nd->pass_activity(last_nd);
	if(en->edge_occ [rnb_left] == en->edge_occ [rnb_right])
	{
		for(int k=0; dc->Gp->inf(en->edge_occ [rnb_left])->tree_occ [[i][k];k++)
		{
		dc->Gp->inf(en->edge_occ [rnb_left])->tree_occ [[i][k] = new_occ;
		}
	}
	else
	{
		for(int k=0 en != dc->Gp->inf(en->edge_occ rnb_left])->tree_occ [[i] [k];k++)
			dc->Gp->inf(en->edge_occ rnb_left])->tree_occ [i] k] = new_occ;
	}
	edge first_edge = first_nd->edge_occ [rnb_right];
	if((first_edge != last_nd->edge_occ [rnb_left]) ||(en == last_nd))
	{
		for(int k=0 first_nd != dc->Gp->inf(first_edge)->tree_occ [[i] [k];k++)
			dc->Gp->inf(first_edge)->tree_occ [[i] [k] = last_nd;
	}
	else
	{	
		for(int k=0 ;first_nd != dc->Gp->inf(first_edge)->tree_occ[ [i][ k];k++)
			dc->Gp->inf(first_edge)->tree_occ [[i] [k] = nil;
	}


	last_nd->edge_occ [rnb_right] = first_edge;

	new_occ->edge_occ [rnb_left] = en->edge_occ [rnb_left];
	en->edge_occ [rnb_left] = nil;
	et_tree s1, s2;
	split(first_nd,rnb_right,s1,s2,dc->et_dummy);
	delete first_nd;
	split(en,rnb_left,s1,s2,dc->et_dummy);
	et = et_join(s2,et_join(s1,new_occ,dc->et_dummy),dc->et_dummy);
}



et_tree et_link(node u, node v, edge e, int i, dyn_con* dc)
{

	et_node u_act = dc->Gp->inf(u)->act_occ [[i];
	et_node v_act = dc->Gp->inf(v)->act_occ [[i];
	et_node new_u_occ = new et_node_struct(u_act);

	et_tree etv = v_act->find_root();
	change_root(etv,v_act,i,dc);

	dc->Gp->inf(e)->tree_occ [i] [0] = u_act;
	dc->Gp->inf(e)->tree_occ [i] [1] = new_u_occ;

	et_node etv_last = etv->last();
	dc->Gp->inf(e)->tree_occ [[i] [3] = etv_last;
	if(etv_last != v_act) 
		dc->Gp->inf(e)->tree_occ [[i] [2] = v_act;
	else
		dc->Gp->inf(e)->tree_occ [[i] [2] = nil;

	edge after_e = u_act->edge_occ [rnb_right];
	if(after_e)
	{
		if(u_act->edge_occ [rnb_left] != after_e)
		{

			for(int k=0 ;u_act != dc->Gp->inf(after_e)->tree_occ [[i] [k]; k++)
				dc->Gp->inf(after_e)->tree_occ [[i] [k] = new_u_occ;
		}
		else
		{

			for(int k=0 ;nil != dc->Gp->inf(after_e)->tree_occ [[i] [k]; k++)
				dc->Gp->inf(after_e)->tree_occ [[i] [k] = new_u_occ;
		}
	}

	new_u_occ->edge_occ rnb_right] = u_act->edge_occ [rnb_right];
	new_u_occ->edge_occ [rnb_left] = e;
	u_act->edge_occ [rnb_right] = e;
	v_act->edge_occ [rnb_left] = e;
	etv_last->edge_occ [rnb_right] = e;

	etv = et_join(etv,new_u_occ,dc->et_dummy);

	et_tree s1, s2;
	split(u_act,rnb_right,s1,s2,dc->et_dummy);

	return et_join(s1,et_join(etv,s2,dc->et_dummy),dc->et_dummy);
}





void et_cut(edge e, int i, dyn_con* dc)
{

	et_node ea1 = dc->Gp->inf(e)->tree_occ [[i] [0];
	et_node ea2 = dc->Gp->inf(e)->tree_occ [[i] [1];
	et_node eb1 = dc->Gp->inf(e)->tree_occ [[i] [2];
	et_node eb2 = dc->Gp->inf(e)->tree_occ [[i] [3];

	dc->Gp->inf(e)->tree_occ [[i][0]=nil;
	dc->Gp->inf(e)->tree_occ [[i][0]=nil;
	dc->Gp->inf(e)->tree_occ [[i][0]=nil;
	dc->Gp->inf(e)->tree_occ [[i][0]=nil;

	et_node aux;
	if(ea1 && ea2)
	{
		if(smaller(ea2,ea1))
		{
			aux = ea1; ea1 = ea2; ea2 = aux;
		}
	}
	else
	{
		if(ea1)
		{
			ea2 = ea1 ;ea1 = nil;
		}
	}
	if(eb1 && eb2)
	{
		if(smaller(eb2,eb1))
		{
			aux = eb1; eb1 = eb2; eb2 = aux;
		}
	}
	else
	{
		if(eb1)
		{
			eb2 = eb1; eb1 = nil;
		}
	}



	if(smaller(ea2,eb2))
	{
		aux = eb1; eb1 = ea1; ea1 = aux;
		aux = eb2; eb2 = ea2 ;ea2 = aux;
	}
	et_tree s1, s2, s3;
	split(ea1,rnb_right,s1,s2,dc->et_dummy);
	split(ea2,rnb_right,s2,s3,dc->et_dummy);

	et_join(s1,s3,dc->et_dummy);

	split(eb2,rnb_right,s1,s2,dc->et_dummy);

	if(ea2->active) 
		ea2->pass_activity(ea1);

	edge after_e = ea2->edge_occ [rnb_right];
	if(after_e)
	{
		if(ea1->edge_occ [rnb_left] != after_e)
		{
			for(int k=0; ea2 != dc->Gp->inf(after_e)->tree_occ [[i] [k];k++)
				dc->Gp->inf(after_e)->tree_occ [[i] [k] = ea1;
		}
		else
		{
		for(int k=0; ea2 != dc->Gp->inf(after_e)->tree_occ [[i] [k];k++)
			dc->Gp->inf(after_e)->tree_occ [[i] [k] = nil;
		}
	}

	ea1->edge_occ [rnb_right] = ea2->edge_occ [rnb_right];
	if(eb1) 
		eb1->edge_occ [rnb_left] = nil;
	else
		eb2->edge_occ [rnb_left] = nil;
	eb2->edge_occ [rnb_right] = nil;

	delete ea2;
}








class dyn_con
{
	public:
	dyn_con(dc_graph& G, int ml_reb_bound = -1, int n_levels = -1,int edges_to_samp = -1, int small_w = -1, int small_s = -1);
	~dyn_con();
	edge ins(node u, node v);
	void del(edge e);
	bool connected(node u, node v);
	private:
	friend class et_node_struct;
	friend void change_root(et_tree& et, et_node en, int i, dyn_con* dc);
	friend et_tree et_link(node u, node v, edge e, int i, dyn_con* dc);
	friend void et_cut(edge e, int i, dyn_con* dc);
	
	
	
	dc_graph  *Gp ;
	int max_level ;
	list<edge> *tree_edges ;
	list<edge> *non_tree_edges ;
	int *added_edges ;
	
	
	int *rebuild_bound;
	int small_weight;
	int edges_to_sample;
	int small_set;
	et_node et_dummy;
	ed_node ed_dummy;
	
	bool connected(node x, node y, int i);
	bool tree_edge(edge e);
	int level(edge e);
	void insert_tree(edge e, int i, bool create_tree_occs = false);
	void delete_tree(edge e);
	void replace(node u, node v, int i);
	void rebuild(int i);
};



edge dyn_con::ins(node u, node v)
{
	edge e = Gp->new_edge(u,v);
	(*Gp) [e] = new dc_edge_struct();
	if(!connected(u,v,max_level))
	{
		insert_tree(e,max_level,true);
		added_edges [max_level]++;
		rebuild(max_level);
	}
	else
	{
		int curr_level = max_level/2;
		int lower = 0;
		int upper = max_level;
		while(curr_level != lower)
		{
			if(connected(u,v,curr_level))
			{
				upper = curr_level;
				curr_level = (lower + curr_level)/2;
			}
			else
			{
				lower = curr_level;
				curr_level = (upper + curr_level)/2;
			}
		}
		if(!connected(u,v,lower)) 
			lower++;
		insert_non_tree(e,lower);
		added_edges [lower]++;
		rebuild(lower);
	}
	return e;
}


void dyn_con::del(edge e)
{
	if(!tree_edge(e)) delete_non_tree(e);
	else
	{
		int e_level = level(e);
		node u = source(e);
		node v = target(e);
		delete_tree(e);
		for(int j=0; j<=max_level; j++) 
			delete [] (*Gp) [e]->tree_occ [[j];
		delete [] (*Gp) [e]->tree_occ
	}
	replace(u,v,e_level);
	delete (*Gp) [e];
	(*Gp) [e] = nil;
	Gp->del_edge(e);
}


bool dyn_con::connected(node u, node v)
{
	return connected(u,v,max_level);
}

bool dyn_con::connected(node x, node y, int i)
{
	et_node x_act_occ = (*Gp) x]->act_occ [[i];
	et_node y_act_occ = (*Gp) y]->act_occ [[i];
	return (x_act_occ->find_root() == y_act_occ->find_root());
}

inline bool dyn_con::tree_edge(edge e)
{
	return ((*Gp) [e]->tree_occ != nil);
}

inline int dyn_con::level(edge e)
{
	return (*Gp) [e]->level;
}

void dyn_con::insert_tree(edge e, int i, bool create_tree_occs)
{
	node u = source(e);
	node v = target(e);
	(*Gp) [e]->level = i;
	if(create_tree_occs)
	{
		(*Gp) [e]->tree_occ = new et_node* [max_level+1];
		for(int lev=0; lev<=max_level ;lev++)
		{
			(*Gp) [e]->tree_occ [lev][ [j] = new et_node [4];
		for(int j=0 j<4 j++) 
			(*Gp) [e]->tree_occ [lev][ [j] = nil;
		}
	}
	for(int j=i ;j<=max_level; j++) et_link(u,v,e,j,this);
	(*Gp) [e]->tree_item = tree_edges [i].append(e);
}

void dyn_con::delete_tree(edge e)
{
	int i = level(e);

	for(int j=i; j<=max_level ;j++) et_cut(e,j,this);
	tree_edges [i].del_item((*Gp) [e]->tree_item);
	(*Gp) [e]->tree_item = nil;
}


void dyn_con::replace(node u, node v, int i)
{
	et_tree t1 = (*Gp) u]->act_occ [i]->find_root();
	et_tree t2 = (*Gp) v]->act_occ [i]->find_root();

	if(t1->get_subtree_weight() > t2->get_subtree_weight()) t1 = t2;
	int handle_cut = false;
	if(t1->get_subtree_weight() > small_weight)
	{
		int not_done = true;
		edge e
		for(int j=0 not_done && (j<edges_to_sample) j++)
		{
			e = sample_and_test(t1,i);
			if(e) not_done = false;
		}
		if(e)
		{
			delete_non_tree(e);
			insert_tree(e,i,true);
		}
		else
		{
			handle_cut = true;
		}
	}
	else
	{
		handle_cut = true;
	}
	if(handle_cut)
	{
		list<edge> cut_edges;
		if(t1->get_subtree_weight() > 0)
		{
			get_cut_edges(t1,i,cut_edges);
		}
		if(cut_edges.size() == 0)
	{
		if(i<max_level) replace(u,v,i+1)
	}
	else // cut_edges.size() > 0
	{
		if(cut_edges.size() >= t1->get_subtree_weight()/small_set)
		{
			edge reconnect = cut_edges.pop();
			delete_non_tree(reconnect);
			insert_tree(reconnect,i,true);
		}
else
{
edge reconnect = cut_edges.pop();
delete_non_tree(reconnect);
if(i<max_level)
{
insert_tree(reconnect,i+1,true);
added_edges [i+1]++
edge e;
forall(e,cut_edges)
{
delete_non_tree(e)
insert_non_tree(e,i+1)
added_edges [i+1]++
}
#ifdef STATISTICS
edges_moved_up += cut_edges.size() + 1
#endif
rebuild(i+1)
}
else
// on top level, no moving of edges
{
insert_tree(reconnect,i,true)
}
}
}
}
}
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.5
sample and test
Internal Functions 66] +
f
edge dyn_con::sample_and_test(et_tree T, int i)
// Randomly select a non-tree edge of G_i that has at least one
// endpoint in T, where an edge with both endpoints in T is picked
// with 2/w(T) and an edge with exactly one endpoint in T is picked
// with probability 1/w(T).
// Test if exactly one endpoint is in T, and if so, return the edge.
// Otherwise return nil.
{
#ifdef STATISTICS
n_sample_and_test++
#endif
// get the number of adjacencies
int no_of_adj = T->get_subtree_weight()
// pick a random one
int rnd_adj = 1 + (random() % no_of_adj)
// locate the et_node representing this adjacency and get the corr. node
int offset
et_node et_repr = et_locate(T,rnd_adj,offset)
node u = et_repr->get_corr_node()
// locate the edge corresp. to offset adjacent to u at level i
ed_node en = ed_locate((*Gp) u]->adj_edges [i],offset,offset)
edge e = en->get_corr_edge()
// get the second node of e
node v = (source(e) == u) ? target(e) : source(e)
}
g
// if v is in a different tree at level i then return e else nil
if(connected(u,v,i)) return nil
else
return e
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.6
get cut edges
Internal Functions 67] +
f
void dyn_con::traverse_edges(ed_node ed, list<edge>& edge_list)
// append edges with exactly one endpoint in subtree rooted at ed to edge_list
// auxiliary function called by get_cut_edges
{
if(ed)
{
edge e = ed->get_corr_edge()
if(!connected(source(e),target(e),level(e)))
{
// only one endpoint of e in current spanning tree -> append edge
edge_list.append(e)
}
}
}
traverse_edges(ed->left_child(),edge_list)
traverse_edges(ed->right_child(),edge_list)
void dyn_con::get_cut_edges(et_node u, int level, list<edge>& result)
// Return the edges with exactly one endpoint in the et_tree rooted at u
// in result.
{
if(u && u->get_subtree_weight())
{
node v = u->get_corr_node()
if(u->is_active()) traverse_edges((*Gp) v]->adj_edges level],result)
get_cut_edges(u->left_child(),level,result)
get_cut_edges(u->right_child(),level,result)
}
}
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.7
insert non tree
Internal Functions 68] +
f
void dyn_con::insert_non_tree(edge e, int i)
// Insert the non-tree edge e into G_i.
{
#ifdef STATISTICS
n_ins_non_tree++
#endif
#ifdef DEBUG
cout << "(" << index(source(e)) << "," << index(target(e))
cout << ") non-tree ins at level " << i << "\n"
#endif
(*Gp) [e]->level = i
node u = source(e)
node v = target(e)
// insert e in the adjacency trees of its endpoints at level i
(*Gp) [e]->non_tree_occ 0] =
ed_insert((*Gp) u]->adj_edges [i],e,ed_dummy)
(*Gp) [e]->non_tree_occ 1] =
ed_insert((*Gp) v]->adj_edges [i],e,ed_dummy)
// update non_tree_edges [i]
(*Gp) [e]->non_tree_item = non_tree_edges [i].append(e)
}
// increase the weight of the active occurrences of u and v at level i
(*Gp) u]->act_occ [i]->add_weight(1)
(*Gp) v]->act_occ [i]->add_weight(1)
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.8
delete non tree
Internal Functions 69] +
f
void dyn_con::delete_non_tree(edge e)
// Delete the non-tree edge e.
{
#ifdef STATISTICS
n_del_non_tree++
#endif
// find the endpoints and the level of e
node u = source(e)
node v = target(e)
int i = level(e)
#ifdef DEBUG
cout << "(" << index(source(e)) << "," << index(target(e))
cout << ") non-tree del at level " << i << "\n"
#endif
// remove e from the ed_trees of u and v at level i
ed_delete((*Gp) u]->adj_edges [i],(*Gp) [e]->non_tree_occ 0],ed_dummy)
(*Gp) [e]->non_tree_occ 0] = nil
ed_delete((*Gp) v]->adj_edges [i],(*Gp) [e]->non_tree_occ 1],ed_dummy)
(*Gp) [e]->non_tree_occ 1] = nil
// remove e from the list of non-tree edges at level i
non_tree_edges [i].del_item((*Gp) [e]->non_tree_item)
(*Gp) [e]->non_tree_item = nil
}
// decrease the weights of the active occurrences of u and v if they exist
(*Gp) u]->act_occ [i]->add_weight(-1)
(*Gp) v]->act_occ [i]->add_weight(-1)
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.9
rebuild
Internal Functions 70] +
f
void dyn_con::rebuild(int i)
// does a rebuild at level i if necessary
{
// rebuilds take place only at level 3 and higher
if(i<3) return
// count added edges at level j>=i
int sum_added_edges = 0
for(int j=i ;j<=max_level; j++) sum_added_edges += added_edges [j]
if(sum_added_edges > rebuild_bound [i])
{
#ifdef DEBUG
cout << "rebuild(" << i << ")\n"
#endif
// move edges down
move_edges(i)
for(j=i ;j<=max_level; j++) added_edges [j] = 0
}
}
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.10
move edges
The purpose of move edges(i) is to move all edges at each level j with j i to level i-1. We can easily
access the edges at level j by means of the lists non tree edges [j] and tree edges [j]. We move a non-tree
edge e by a pair of delete non tree(e) and insert non tree(e,i-1) calls.
In principle we could also move the tree edges in the same manner by using delete tree and insert tree.
However, if i is close to j and both are relatively small compared to max level, this would be a waste of
time, since it means also splitting all corresponding et trees at levels j to max level and then joining them
again. We just x the lists of tree edges and et join the a ected trees on levels i-1 to j-1, instead.
Internal Functions 71] +
f
void dyn_con::move_edges(int i)
// For j>=i, insert all edges of F_j into F_{i-1}, and all
// non-tree edges of G_j into G_{i-1}.
{
#ifdef STATISTICS
n_move_edges++
#endif
// for each level starting at max_level and ending at i...
for(int j=max_level j>=i j--)
{
#ifdef STATISTICS
edges_moved_down += non_tree_edges [j].size() + tree_edges [j].size()
#endif
// move non-tree edges
while(non_tree_edges [j].size())
{
edge e = non_tree_edges [j].head()
// delete non-tree edge at level j ...
delete_non_tree(e)
// ... and insert it into level i-1
insert_non_tree(e,i-1)
}
// move tree edges
while(tree_edges [j].size())
{
edge e = tree_edges [j].head()
// update tree_edges [j], tree_edges i-1], tree_item and level
tree_edges [j].del_item(Gp->inf(e)->tree_item)
Gp->inf(e)->tree_item = tree_edges i-1].append(e)
Gp->inf(e)->level = i-1
}
}
}
// link the corresponding et_trees from level i-1 to j-1
for(int k=i-1 k<j k++)
{
et_link(source(e),target(e),e,k,this)
}
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.11 Constructor
There are ve optional parameters which can be given to the constructor in order to adapt the data structure
to a special input situation. These are ml rebuild bound which speci es the bound for newly inserted edges
on the highest level before that level is rebuilt, and n levels which speci es the number of levels. Moreover
the user can prescribe the di erent bounds which are used in the replacement algorithm for a deleted forest
edge. Note that the asymptotic analysis may no longer be valid if you choose your own number of levels or
bounds.
Internal Functions 72] +
f
dyn_con::dyn_con(dc_graph& G, int ml_reb_bound, int n_levels,
int edges_to_samp, int small_w, int small_s)
// constructor, initializes the dynamic connectivity data structure
// if ml_reb_bound >= 1 it specifies rebuild_bound max_level] (default is 5000)
// if n_levels > 0 then it specifies the number of levels (default O(log n))
// if edges_to_samp >= 0 then it specifies edges_to_sample (default 32 log^2 n)
// if small_w >= 0 then it specifies small_weight (default log^2 n)
// if small_s >= 1 then it specifies small_set (default 16 log n)
{
// --- initialize random numbers ---
struct timeval dummy1
struct timezone dummy2
gettimeofday(&dummy1,&dummy2)
srandom(dummy1.tv_sec+dummy1.tv_usec)
// --- initialize the constants ---
Gp = &G
int log_n = 0
for(int i = G.number_of_nodes() i i /= 2) log_n++
if(small_w>=0) small_weight = small_w
small_weight = log_n * log_n
else
if(edges_to_samp>=0) edges_to_sample = edges_to_samp
else
edges_to_sample = 32 * log_n * log_n
if(small_s>=1) small_set = small_s
else
small_set = 16 * log_n
if(n_levels > 0) max_level = n_levels - 1
else
{
max_level = 6 * log_n
for(int k=4 (k<ml_reb_bound) && (max_level>=2)
}
#ifdef
cout
cout
cout
cout
#endif
DEBUG
<< "|V(G)|
<< "max_level
<< "edges_to_sample
<< "small_set
=
=
=
=
"
"
"
"
<<
<<
<<
<<
k *= 2, max_level--)
G.number_of_nodes() << "\n"
max_level << "\n"
edges_to_sample << "\n"
small_set << "\n\n"
// --- initialize dummy nodes ---
et_dummy = new et_node_struct(this,nil)
ed_dummy = new ed_node_struct(nil)
// --- initialize the edge lists ---
non_tree_edges = new list<edge> [max_level+1]
tree_edges = new list<edge> [max_level+1]
// --- initialize added_edges ---
added_edges = new int [max_level+1]
for(i=0 i<=max_level i++) added_edges [i] = 0
// --- initialize rebuild_bound ---
rebuild_bound = new int [max_level+1]
int bound
if(ml_reb_bound>=1) bound = ml_reb_bound
else
bound = 5000
for(int k=max_level k>=0 k--)
{
rebuild_bound k] = bound
if(bound < MAXINT/2) bound *= 2
// double the bound if possible
}
// --- initialize the nodes ---
node u
forall_nodes(u,G)
{
G u] = new dc_node_struct()
G u]->act_occ = new et_node [max_level+1]
G u]->adj_edges = new ed_tree [max_level+1]
for(i=0 i<=max_level i++)
{
G u]->act_occ [i] = new et_node_struct(this,u,i,true)
G u]->adj_edges [i] = nil
}
}
// --- initialize the edges ---
edge e
forall_edges(e,G)
{
G e] = new dc_edge_struct()
}
if(!connected(source(e),target(e),0)) insert_tree(e,0,true)
else
insert_non_tree(e,0)
#ifdef STATISTICS
// --- initialize statistics ---
n_ins = 0
n_del = 0
n_query = 0
n_connected = 0
n_ins_tree = 0
n_del_tree = 0
n_replace = 0
rep_succ = 0
rep_big_cut = 0
rep_sparse_cut = 0
rep_empty_cut = 0
rep_small_weight = 0
n_sample_and_test = 0
n_get_cut_edges = 0
n_ins_non_tree = 0
n_del_non_tree = 0
n_move_edges = 0
edges_moved_up = 0
edges_moved_down = 0
#endif
}
g
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.
8.6.12 Destructor
The destructor deallocates all additional memory used for the dynamic connectivity data structure, but it
does not delete the nodes and edges of the graph.
Internal Functions 73] +
f
dyn_con::~dyn_con()
{
// first delete all edges in the data structure (not in G)
edge e
forall_edges(e,*Gp)
{
if(tree_edge(e))
{
delete_tree(e)
for(int j=0 ;j<=max_level; j++) delete ] (*Gp) [e]->tree_occ [j]
delete ] (*Gp) [e]->tree_occ
}
else delete_non_tree(e)
}
delete (*Gp) [e]
(*Gp) [e] = nil
// delete fields (edge lists are empty, no need to clear() them)
delete ] non_tree_edges
delete ] tree_edges
delete ] added_edges
delete ] rebuild_bound
// delete the et_nodes and the information at the nodes of G
node v
forall_nodes(v,*Gp)
{
// per node of G only its active occurrence at each level is left
for(int i=0 i<=max_level i++) delete (*Gp) v]->act_occ [i]
delete ] (*Gp) v]->act_occ
delete ] (*Gp) v]->adj_edges
}
g
}
delete (*Gp) v]
(*Gp) v] = nil
This macro is de ned in de nitions 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, and 73.
This macro is invoked in de nition 55.









class dc_node_struct
{
	public:
	et_node *act_occ;
	ed_tree *adj_edges;

	dc_node_struct()
	{ 
		act_occ = nil; 
		adj_edges = nil;
	}
};
class dc_edge_struct
{
	public:
	int level;
	list_item non_tree_item;
	list_item tree_item;
	ed_node non_tree_occ [2];
	et_node **tree_occ;
	dc_edge_struct()
	{ 
		non_tree_item = nil ;
		tree_item = nil;
		non_tree_occ [0] = non_tree_occ [1] = nil;
		tree_occ = nil;
	}
};
typedef dc_node_struct* dc_node_inf;
typedef dc_edge_struct* dc_edge_inf;
typedef GRAPH<dc_node_inf,dc_edge_inf> dc_graph;







