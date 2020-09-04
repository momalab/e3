module isort_round (
input wire [7:0] previous_in,
input wire [7:0] current_in,
output wire [7:0] previous_out,
output wire [7:0] current_out
);
assign previous_out = (previous_in > current_in) ? current_in : previous_in;
assign current_out  = (previous_in > current_in) ? previous_in : current_in;
endmodule
