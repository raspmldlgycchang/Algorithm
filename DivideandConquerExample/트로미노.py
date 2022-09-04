def tromino(size, board, srow, scol,xrow, xcol):

    # 구멍이 없는 게 확인되면 fill 함수로 구멍을 넣어주기
    # 구멍 위치는 mrow-1, mcol-1
    mrow = srow + (size // 2)
    mcol = scol + (size // 2)

    where = whereis(size, srow, scol,xrow, xcol)
    if size==2:
        fill(size, board, srow, scol, where)
    else:
        fill(size, board,srow+mrow-1, scol+mcol-1, where)
        # 구멍 위치를 찾은 후에
        hrow, hcol = hole(1, size, where, board, srow, scol, xrow, xcol)
        # 현재 사사분면으로 나눠진 상태를 모든 사분면에 대해서 호출해야 하니까
        # 현재 srow, scol, size 를 써야 한다
        tromino(size//2, board, srow, scol, xrow, xcol)
        hrow, hcol = hole(2, size, where, board, srow, scol, xrow, xcol)
        tromino(size//2, board, srow, mcol,xrow, xcol)
        hrow, hcol = hole(3, size, where, board, srow, scol, xrow, xcol)
        tromino(size//2, board, mrow, scol, xrow, xcol)
        hrow, hcol = hole(4, size, where, board, srow, scol, xrow, xcol)
        tromino(size//2, board, mrow, mcol, xrow, xcol)

def fill(n, board, srow, scol, where):
    if where!=1:    board[srow][scol] = n
    if where!=2:    board[srow][scol+1] = n
    if where!=3:    board[srow+1][scol] = n
    if where!=4:    board[srow+1][scol+1] = n

def hole(part, n, where, board, srow, scol, virtual_hrow, virtual_hcol):
    m = n//2

    if part!=where:
        virtual_hrow, virtual_hcol = srow+m-1, scol+m-1
        if part==2 or part==4:  virtual_hcol += 1
        if part==3 or part==4:  virtual_hrow += 1

    return virtual_hrow, virtual_hcol

def whereis(size, srow, scol, xrow, xcol):
    m = size//2

    if xrow-srow<m:
        return 1 if xcol-scol<m else 2
    else:
        return 3 if xcol-scol<m else 4