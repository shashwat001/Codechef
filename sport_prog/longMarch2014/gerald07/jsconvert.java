
class Treap
{


	int value;
	boolean flag;
	boolean flagAggregate;
	int count;
	int priority;
	Treap parent;
	Treap left;
	Treap right;
	Treap next;
	Treap prev;
  
	int countOfValue(Treap v) 
	{
	  Treap t = v;
	  if(t) 
	  {
		return (t === "vertex" ? 1 : 0)
	  }
	  return 1
	}

	Treap(EulerHalfEdge value) 
	{
	  return new TreapNode(value, false, false, countOfValue(value), Math.random(), null, null, null, null, null)
	}

	Treap(int value,boolean flag,boolean flagAggregate, int  count, int priority,Treap parent,Treap  left,Treap  right,Treap  next,Treap  prev) {
	  this.value = value;
	  this.flag = flag;
	  this.flagAggregate = flagAggregate;
	  this.count = count;
	  this.priority = priority;
	  this.parent = parent;
	  this.left = left;
	  this.right = right;
	  this.next = next;
	  this.prev = prev;
	}



	void bubbleUp() 
	{
	  while(1!=0) 
	  {
		Treap p = this.parent;
		if(p==0 || p.priority < this.priority) 
		{
		  break;
		}
		if(this == p.left) 
		{
		  Treap b = this.right;
		  p.left = b;
		  if(b!=null) 
		  {
		    b.parent = p;
		  }
		  this.right = p;
		} else 
		{
		  Treap b = this.left;
		  p.right = b;
		  if(b!=null) 
		  {
		    b.parent = p;
		  }
		  this.left = p;
		}
		p.update();
		this.update();
		Treap gp = p.parent;
		p.parent = this;
		this.parent = gp;
		if(gp!=null) 
		{
		  if(gp.left == p) 
		  {
		    gp.left = this;
		  } 
		  else 
		  {
		    gp.right = this;
		  }
		}
	  }
	  Treap p = this.parent;
	  while(p!=null) 
	  {
		p.update();
		p = p.parent;
	  }
	}

	Treap root()
	{
	  Treap n = this;
	  while(n.parent!=null) 
	  {
		n = n.parent;
	  }
	  return n;
	}

	Treap first()
	{
	  Treap l = this.root();
	  while(l.left!=null) 
	  {
		l = l.left;
	  }
	  return l;
	}

	Treap last()
	{
	  Treap r = this.root();
	  while(r.right!=null) 
	  {
		r = r.right;
	  }
	  return r;
	}

	Treap insert(EulerHalfEdge value)
	{
	  if(this.right==null) 
	  {
		Treap nn = this.right = new Treap(value, false, false, countOfValue(value), Math.random(), this, null, null, this.next, this)
		if(this.next!=null) 
		{
		  this.next.prev = nn;
		}
		this.next = nn;
		nn.bubbleUp();
		return nn;
	  }
	  Treap v = this.next;
	  Treap nn = v.left = new Treap(value, false, false, countOfValue(value), Math.random(), v, null, null, v, this)
	  v.prev = nn;
	  this.next = nn;
	  nn.bubbleUp();
	  return nn;
	}

	void swapNodes(Treap a, Treap b) {
	  boolean p = a.priority;
	  a.priority = b.priority;
	  b.priority = p;
	  Treap t = a.parent;
	  a.parent = b.parent;
	  if(b.parent!=null) 
	  {
		if(b.parent.left == b) 
		{
		  b.parent.left = a;
		} 
		else 
		{
		  b.parent.right = a;
		}
	  }
	  b.parent = t;
	  if(t!=null) 
	  {
		if(t.left == a) 
		{
		  t.left = b;
		} 
		else 
		{
		  t.right = b;
		}
	  }
	  t = a.left;
	  a.left = b.left;
	  if(b.left!=null) 
	  {
		b.left.parent = a;
	  }
	  b.left = t;
	  if(t!=null) 
	  {
		t.parent = b;
	  }
	  t = a.right;
	  a.right = b.right;
	  if(b.right!=null) 
	  {
		b.right.parent = a;
	  }
	  b.right = t;
	  if(t!=null) 
	  {
		t.parent = b;
	  }
	  t = a.next;
	  a.next = b.next;
	  if(b.next!=null) 
	  {
		b.next.prev = a;
	  }
	  b.next = t;
	  if(t!=null) 
	  {
		t.prev = b;
	  }
	  t = a.prev;
	  a.prev = b.prev;
	  if(b.prev!=null) 
	  {
		b.prev.next = a;
	  }
	  b.prev = t;
	  if(t!=null) 
	  {
		t.next = b;
	  }
	  int c = a.count;
	  a.count = b.count;
	  b.count = c;
	  boolean f = a.flag;
	  a.flag = b.flag;
	  b.flag = f;
	  f = a.flagAggregate;
	  a.flagAggregate = b.flagAggregate;
	  b.flagAggregate = f;
	}

	void update() 
	{
	  int c = countOfValue(this.value)
	  boolean f = this.flag
	  if(this.left !=0) 
	  {
		c += this.left.count;
		f = f || this.left.flagAggregate;
	  }
	  if(this.right!=null) 
	  {
		c += this.right.count;
		f = f || this.right.flagAggregate;
	  }
	  this.count = c;
	  this.flagAggregate = f;
	}

//Set new flag state and propagate up tree
	void setFlag(boolean f) 
	{
	  this.flag = f;
	  for(Treap v=this; v!=null; v=v.parent) 
	  {
		boolean pstate = v.flagAggregate;
		v.update();
		if(pstate == v.flagAggregate) 
		{
		  break;
		}
	  }
	}

	void remove() 
	{
	  Treap node = this;
	  if(node.left!=null && node.right!=null) 
	  {
		Treap other = node.next;
		swapNodes(other, node);
	  }
	  if(node.next!=null) 
	  {
		node.next.prev = node.prev;
	  }
	  if(node.prev!=null) 
	  {
		node.prev.next = node.next;
	  }
	  Treap r = null;
	  if(node.left!=null) 
	  {
		r = node.left;
	  } else 
	  {
		r = node.right;
	  }
	  if(r!=null) 
	  {
		r.parent = node.parent;
	  }
	  if(node.parent!=null) 
	  {
		if(node.parent.left == node) 
		{
		  node.parent.left = r;
		} 
		else 
		{
		  node.parent.right = r;
		}
		//Update all ancestor counts
		Treap p = node.parent;
		while(p!=null) 
		{
		  p.update();
		  p = p.parent;
		}
	  }
	  //Remove all pointers from detached node
	  node.parent = node.left = node.right = node.prev = node.next = null;
	  node.count = 1;
	}

	Treap split() 
	{
	  Treap node = this;
	  Treap s = node.insert();
	  s.priority = -Infinity;
	  s.bubbleUp();
	  Treap l = s.left;
	  Treap r = s.right;
	  if(l!=null) 
	  {
		l.parent = null;
	  }
	  if(r!=null) 
	  {
		r.parent = null;
	  }
	  if(s.prev!=null) 
	  {
		s.prev.next = null;
	  }
	  if(s.next!=null) 
	  {
		s.next.prev = null;
	  }
	  return r;
	}

	Treap concatRecurse(Treap a, Treap b) 
	{
	  if(a == null) 
	  {
		return b;
	  } 
	  else if(b == null) 
	  {
		return a;
	  } 
	  else if(a.priority < b.priority) 
	  {
		a.right = concatRecurse(a.right, b);
		a.right.parent = a;
		a.update();
		return a;
	  } 
	  else 
	  {
		b.left = concatRecurse(a, b.left);
		b.left.parent = b;
		b.update();
		return b;
	  }
	}

	Treap concat(Treap other) 
	{
	  if(other==null) 
	  {
		return null;
	  }
	  Treap ra = this.root();
	  Treap ta = ra;
	  while(ta.right!=null) 
	  {
		ta = ta.right;
	  }
	  Treap rb = other.root();
	  Treap sb = rb;
	  while(sb.left!=null) 
	  {
		sb = sb.left;
	  }
	  ta.next = sb;
	  sb.prev = ta;
	  Treap r = concatRecurse(ra, rb);
	  r.parent = null;
	  return r;
	}
}

class EulerHalfEdge
{
	int value;
	EulerVertex s;
	EulerVertex t;
	Treap node;
	EulerHalfEdge opposite;
	int type=0;

	EulerHalfEdge(int value,EulerVertex s, EulerVertex t,Treap node,EulerHalfEdge opposite) 
	{
		this.value = value;
		this.s = s;
		this.t = t;
		this.node = node;
		this.opposite = opposite;
	}
	
	void cleanup() 
	{
		Treap v = this.node;
		v.remove();
		v.value = null;
		this.node = null;
		this.opposite = null;
		this.s = null;
		this.t = null;
	}

	void cut() 
	{

		EulerHalfEdge other = this.opposite;

		//Split into parts
		Treap a = this.node;
		Treap b = a.split();
		Treap c = other.node;
		Treap d = c.split();

		//Pull out the roots
		if(d !== null && a.root() !== d.root()) 
		{    //a comes before c:    // [a, bc, d]
			a.concat(d);
		} 
		else if(b !== null && c.root() !== b.root()) 
		{    //c comes before a:    // [c, da, b]
			c.concat(b);
		}

		//Clean up mess
		this.cleanup();
		other.cleanup();
	}


}

class EulerVertex
{
	int value;
	Treap node;
	int type = 1;


	EulerVertex(int value) 
	{
		this.value = value;
		this.node = treap(v);
	}
	
	EulerVertex(int value, Treap node) 
	{
		this.value = value;
		this.node = node;
	}


	//If flag is set, then this vertex has incident edges of at least level v
	void setFlag(boolean f) 
	{
		this.node.setFlag(f);
	}

	boolean path(EulerVertex other) 
	{
	  return (this.node.root() == other.node.root());
	}

	void makeRoot() 
	{
		Treap a = this.node;
		Treap b = a.split();
		if(b!=null) 
		{
		b.concat(a);
		}
	}

	EulerHalfEdge link(EulerVertex other,int value) 
	{
		//Move both vertices to root
		this.makeRoot();
		other.makeRoot();

		//Create half edges and link them to each other
		EulerHalfEdge st = new EulerHalfEdge(value, this, other, null, null);
		EulerHalfEdge ts = new EulerHalfEdge(value, other, this, null, st);
		st.opposite = ts;

		//Insert entries in Euler tours
		st.node = this.node.insert(st);
		ts.node = other.node.insert(ts);

		//Link tours together
		this.node.concat(other.node);

		//Return half edge
		return st;
	}

	int count() 
	{
		return this.node.root().count;
	}

	void cleanup
	{
		this.node.remove();
		this.node.value = null;
		this.node = null;
	}

}


class Vertex
{

ArrayList<EulerVertex> euler;
ArrayList<EulerHalfEdge> adjacent;
int value;

void raiseLevel(edge) 
{
  var s = edge.s
  var t = edge.t

  //Update position in edge lists
  removeEdge(s, edge)
  removeEdge(t, edge)
  edge.level += 1
  elist.insert(s.adjacent, edge)
  elist.insert(t.adjacent, edge)
  
  //Update flags for s
  if(s.euler.length <= edge.level) {
    s.euler.push(createEulerVertex(s))
  }
  var es = s.euler[edge.level]
  es.setFlag(true)

  //Update flags for t
  if(t.euler.length <= edge.level) {
    t.euler.push(createEulerVertex(t))
  }
  var et = t.euler[edge.level]
  et.setFlag(true)

  //Relink if necessary
  if(edge.euler) {
    edge.euler.push(es.link(et, edge))
  }
}

//Remove edge from list and update flags
function removeEdge(vertex, edge) {
  var adj = vertex.adjacent
  var idx = elist.index(adj, edge)
  adj.splice(idx, 1)
  //Check if flag needs to be updated
  if(!((idx < adj.length && adj[idx].level === edge.level) ||
       (idx > 0 && adj[idx-1].level === edge.level))) {
    vertex.euler[edge.level].setFlag(false)
  }
}

//Add an edge to all spanning forests with level <= edge.level
function link(edge) {
  var es = edge.s.euler
  var et = edge.t.euler
  var euler = new Array(edge.level+1)
  for(var i=0; i<euler.length; ++i) {
    if(es.length <= i) {
      es.push(createEulerVertex(edge.s))
    }
    if(et.length <= i) {
      et.push(createEulerVertex(edge.t))
    }
    euler[i] = es[i].link(et[i], edge)
  }
  edge.euler = euler
}

function DynamicEdge(value, key, s, t, level, euler) {
  this.value = value
  this.key = key  //Used to sort edges in list
  this.s = s
  this.t = t
  this.level = level
  this.euler = euler
}

var eproto = DynamicEdge.prototype

eproto.valueOf = function() {
  return this.value
}

eproto.cut = function() {
  var level

  //Don't double cut an edge
  if(!this.s) {
    return
  }

  //Search over tv for edge connecting to tw
  function visit(node) {
    if(node.flag) {
      var v = node.value.value
      var adj = v.adjacent
      for(var ptr=elist.level(adj, level); ptr<adj.length && adj[ptr].level === level; ++ptr) {
        var e = adj[ptr]
        var es = e.s
        var et = e.t
        if(es.euler[level].path(et.euler[level])) {
          raiseLevel(e)
          ptr -= 1
        } else {
          //Found the edge, relink components
          link(e)
          return true
        }
      }
    }
    if(node.left && node.left.flagAggregate) {
      if(visit(node.left)) {
        return true
      }
    }
    if(node.right && node.right.flagAggregate) {
      if(visit(node.right)) {
        return true
      }
    }
    return false
  }

  removeEdge(this.s, this)
  removeEdge(this.t, this)
  if(this.euler) {
    //Cut edge from tree
    for(var i=0; i<this.euler.length; ++i) {
      this.euler[i].cut()
    }

    //Find replacement, looping over levels
    for(var i=this.level; i>=0; --i) {
      var tv = this.s.euler[i].node.root()
      var tw = this.t.euler[i].node.root()
      level = i
      if(tv.count > tw.count) {
        visit(tw)
      } else {
        visit(tv)
      }
    }
  }
  this.s = this.t = this.euler = null
  this.level = 32
}

function DynamicVertex(value, euler, adjacent) {
  this.value = value
  this.euler = euler
  this.adjacent = adjacent
}

var vproto = DynamicVertex.prototype

boolean connected(Vertex other) 
{
  return this.euler[0].path(other.euler[0]);
}

Edge link(Vertex other, int value) 
{
  Edge e = new DynamicEdge(value, (KEY_COUNTER++), this, other, 0, null);
  if(this.euler[0].path(other.euler[0])==false) 
  {
    link(e);
  }
  this.euler[0].setFlag(true);
  other.euler[0].setFlag(true);
  elist.insert(this.adjacent, e);
  elist.insert(other.adjacent, e);
  return e;
}

int valueOf() 
{
  return this.value;
}

//Returns the number of vertices in this connected component
int componentSize() 
{
  return this.euler[0].count();
}

//Removes the vertex from the graph
void cut() 
{
  while(this.adjacent.length > 0) 
  {
    this.adjacent[this.adjacent.length-1].cut();
  }
}

Treap component() 
{
  return new ComponentIterator(this.euler[0].node);
}

Vertex(int value) 
{
	this.value = value;
	ArrayList<EulerVertex> euler = new ArrayList<EulerVertex>;
	ArrayList<Edge> adjacent = new ArrayList<Edge>;
	euler.add(new EulerVertex(this));
}
