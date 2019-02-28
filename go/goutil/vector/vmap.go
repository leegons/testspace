package vector

// Vmap t
type Vmap struct {
	m map[string]*Vector
}

// NewVmap f
func NewVmap() *Vmap {
	return &Vmap{m: make(map[string]*Vector)}
}

// Exists f
func (p *Vmap) Exists(k string) bool {
	_, ok := p.m[k]
	return ok
}

// Add f
func (p *Vmap) Add(k string, v interface{}) {
	if !p.Exists(k) {
		p.m[k] = NewVector()
	}
	p.m[k].Add(v)
}

// ToStrMap f
func (p *Vmap) ToStrMap() map[string][]string {
	res := make(map[string][]string)
	for k, v := range p.m {
		res[k] = make([]string, len(v.v))
		for i, s := range v.v {
			res[k][i] = s.(string)
		}
	}
	return res
}
