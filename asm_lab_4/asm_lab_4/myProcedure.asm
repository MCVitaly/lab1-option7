.686P
.model flat, c
.code

; (4 * x – 1) * (4 * x + 1) / 4

myProcedure		proc x:dword
		mov eax, x
		mov ebx, 4
		imul ebx
		sub eax, 1

		mov ebx, x
		imul ebx, 4
		add ebx, 1

		imul eax, ebx

		mov ebx, 4

		cdq
		idiv ebx

		ret
myProcedure		endp
end