library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity BCD_to_7Segment is
    Port (
        A : in STD_LOGIC;
        B : in STD_LOGIC;
        C : in STD_LOGIC;
        D : in STD_LOGIC;
        a : out STD_LOGIC;
        b : out STD_LOGIC;
        c : out STD_LOGIC;
        d : out STD_LOGIC;
        e : out STD_LOGIC;
        f : out STD_LOGIC;
        g : out STD_LOGIC
    );
end BCD_to_7Segment;

architecture Behavioral of BCD_to_7Segment is
    signal input : STD_LOGIC_VECTOR (3 downto 0);
begin
    input <= A & B & C & D;

    process(input)
    begin
        case input is
            when "0000" => -- 0
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '0';
            when "0001" => -- 1
                a <= '0'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '0'; g <= '0';
            when "0010" => -- 2
                a <= '1'; b <= '1'; c <= '0'; d <= '1'; e <= '1'; f <= '0'; g <= '1';
            when "0011" => -- 3
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '0'; f <= '0'; g <= '1';
            when "0100" => -- 4
                a <= '0'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '1'; g <= '1';
            when "0101" => -- 5
                a <= '1'; b <= '0'; c <= '1'; d <= '1'; e <= '0'; f <= '1'; g <= '1';
            when "0110" => -- 6
                a <= '1'; b <= '0'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '1';
            when "0111" => -- 7
                a <= '1'; b <= '1'; c <= '1'; d <= '0'; e <= '0'; f <= '0'; g <= '0';
            when "1000" => -- 8
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '1'; f <= '1'; g <= '1';
            when "1001" => -- 9
                a <= '1'; b <= '1'; c <= '1'; d <= '1'; e <= '0'; f <= '1'; g <= '1';
            when others =>
                a <= '0'; b <= '0'; c <= '0'; d <= '0'; e <= '0'; f <= '0'; g <= '0';
        end case;
    end process;

end Behavioral;