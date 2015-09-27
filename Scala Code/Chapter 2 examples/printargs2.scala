var i = 0;
while (i < args.length) {
	if(i != 0) {
		print(" ");
	}
	print(args(i));
	
	// Note that ++i or i++ is not allowed.
	i += 1;
}
println();