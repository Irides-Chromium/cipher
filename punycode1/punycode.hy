#!/usr/local/bin/hy
(import sys os)
(import [subprocess [*]])

(cond
[(!= (len sys.argv) 3)
    (usage)
    (exit)]
[(= (get sys.argv 1) "-e")
    (setv uni-hexs (.join " " 
            (list-comp (% "u+%s" (-> (ord char) (hex) (.replace "0x" "")))
                [char (get sys.argv 2)])))
    (setv pipe (Popen ["./punycode" "-e"] :stdin PIPE
            :stdout None :stderr STDOUT))
    (.write pipe.stdin (.encode uni-hexs))
    (.close pipe.stdin)]
    ; (exit (os.system (% "./punycode -e '%s'" uni-hexs)))]
[(= (get sys.argv 1) "-d")
    (setv pipe (Popen ["./punycode" "-d"] :stdin PIPE
            :stdout PIPE :stderr STDOUT))
    (.write pipe.stdin (.encode (get sys.argv 2)))
    (.close pipe.stdin)
    (setv uni-hexs (.readlines pipe.stdout))
    (for [code uni-hexs] (-> (cut code 2) (int 16) (chr) (print :end "")))
    (print)])
