type _atom;
type atom('a) = Kefir.stream_like(_atom, 'a);

[@bs.module "karet.util"] external atom: 'a => atom('a) = "atom";

[@bs.module "karet.util"] external view: Lens.lens_like('t, 'a, 'b) => atom('a) => atom('b) = "view";

[@bs.send] external _modify: atom('a) => ('a => 'a) => unit = "modify";
let modify = (fn, a) => _modify(a, fn);

[@bs.send.pipe: atom('a)] external set: 'a => unit = "set";
