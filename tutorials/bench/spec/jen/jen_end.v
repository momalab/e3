module jen_end (
input wire [7:0] hash_in,
input wire [7:0] n3,
input wire [7:0] n11,
input wire [7:0] n15,
output wire [7:0] hash_out
);
assign hash_out = ((hash_in + (hash_in << n3)) ^ ((hash_in + (hash_in << n3)) >> n11)) + (((hash_in + (hash_in << n3)) ^ ((hash_in + (hash_in << n3)) >> n11)) << n15);
endmodule
