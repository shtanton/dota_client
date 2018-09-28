type lens_like('t, 'a, 'b);
type _lens;
type lens('a, 'b) = lens_like(_lens, 'a, 'b);
type _iso;
type iso('a, 'b) = lens_like(_iso, 'a, 'b);

[@bs.module "partial.lenses"] external compose: lens_like('t, 'a, 'b) => lens_like('s, 'b, 'c) => lens_like('s, 'a, 'c) = "compose";

[@bs.module "partial.lenses"] external iso: ('a => 'b) => ('b => 'a) => iso('a, 'b) = "iso";

[@bs.module "partial.lenses"] external lens: (('a => 'b), (('b, 'a) => 'a)) => lens('a, 'b) = "lens";

let string_of_int = {
	let regex = [%bs.re "/[^0-9]/g"];
	let remove = "";
	iso(
		string_of_int,

	);
};

module Infix = {
	let (<->) = compose;
};
