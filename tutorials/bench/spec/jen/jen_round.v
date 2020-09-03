module jen_round (
input wire [7:0] hash_in,
input wire [7:0] key_value,
input wire [7:0] n10,
input wire [7:0] n6,
output wire [7:0] hash_out
);
assign hash_out = ( (hash_in + key_value) +  ((hash_in + key_value) << n10) ) ^ (( (hash_in + key_value) +  ((hash_in + key_value) << n10) ) >> n6);
endmodule
