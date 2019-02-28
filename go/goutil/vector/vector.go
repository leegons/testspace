package vector

// Vector t
type Vector struct {
	v []interface{}
}

// NewVector f
func NewVector() *Vector {
	return &Vector{v: make([]interface{}, 0)}
}

// Exists f
func (p *Vector) Exists(a interface{}) bool {
	for _, iter := range p.v {
		if iter == a {
			return true
		}
	}
	return false
}

// Add f
func (p *Vector) Add(a interface{}) {
	if !p.Exists(a) {
		p.v = append(p.v, a)
	}
}
